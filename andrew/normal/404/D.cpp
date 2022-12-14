#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define ull unsigned long long

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

const ll MOD = 1e9 + 7;

ll f(ll &a, ll b){
    a = (a + b) % MOD;
    return a;
}

ll dp[1000001][4][4];

bool fl[10];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    cin >> s;
    ll n = s.size();
    string s1 = "012*";
    if(n == 1){
        if(s[0] == '*' || s[0] == '0')vout(1);
        if(s[0] == '?')vout(2);
        vout(0);
    }

    s = "0" + s;
    for(int i = 0; i < 4; i++)if(!(s[1] != '?' && s[1] != s1[i]))
        for(int j = 0; j < 4; j++)if(!(s[2] != '?' && s[2] != s1[j])){
            if(i == 0 && j == 2)continue;
            if(i == 0 && j == 3)continue;
            if(i == 1 && j == 2)continue;
            if(i == 1 && j != 3)continue;
            if(i == 2)continue;
            if(i == 3 && j == 0)continue;
            if(i != 3 && j == 2)continue;
            dp[2][i][j] = 1;
        }
    for(int i = 3; i <= n; i++){
        for(int j = 0; j < 4; j++)fl[j] = 0;
        if(s[i] == '?'){
            for(int j = 0; j < 4; j++)fl[j] = 1;
        }else{
            int kek = s1.find(s[i]);
            fl[kek] = 1;
        }
        if(fl[1])dp[i][0][1] = f(dp[i][0][1], dp[i - 1][0][0]);
        if(fl[0])dp[i][0][0] = f(dp[i][0][0], dp[i - 1][0][0]);

        if(fl[3])dp[i][1][3] = f(dp[i][1][3], dp[i - 1][0][1]);

        if(fl[1])dp[i][0][1] = f(dp[i][0][1], dp[i - 1][1][0]);
        if(fl[0])dp[i][0][0] = f(dp[i][0][0], dp[i - 1][1][0]);

        if(fl[3])dp[i][1][3] = f(dp[i][1][3], dp[i - 1][1][1]);

        if(fl[1])dp[i][3][1] = f(dp[i][3][1], dp[i - 1][1][3]);
        if(fl[2])dp[i][3][2] = f(dp[i][3][2], dp[i - 1][1][3]);
        if(fl[3])dp[i][3][3] = f(dp[i][3][3], dp[i - 1][1][3]);

        if(fl[1])dp[i][3][1] = f(dp[i][3][1], dp[i - 1][2][3]);
        if(fl[2])dp[i][3][2] = f(dp[i][3][2], dp[i - 1][2][3]);
        if(fl[3])dp[i][3][3] = f(dp[i][3][3], dp[i - 1][2][3]);

        if(fl[0])dp[i][1][0] = f(dp[i][1][0], dp[i - 1][3][1]);
        if(fl[1])dp[i][1][1] = f(dp[i][1][1], dp[i - 1][3][1]);

        if(fl[3])dp[i][2][3] = f(dp[i][2][3], dp[i - 1][3][2]);

        if(fl[1])dp[i][3][1] = f(dp[i][3][1], dp[i - 1][3][3]);
        if(fl[2])dp[i][3][2] = f(dp[i][3][2], dp[i - 1][3][3]);
        if(fl[3])dp[i][3][3] = f(dp[i][3][3], dp[i - 1][3][3]);

    }
    ll ans = dp[n][0][0];
    ans = f(ans, dp[n][1][0]);
    ans = f(ans, dp[n][3][1]);
    ans = f(ans, dp[n][1][3]);
    ans = f(ans, dp[n][2][3]);
    ans = f(ans, dp[n][3][3]);
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}