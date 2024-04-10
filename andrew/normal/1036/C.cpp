#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

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

ll dp[20][10][2];

ll f(ll x){
    ll res = 0;
    if(!x)return 0;
    ll log = 0, k = x;
    vector <ll> a;
    while(k){
        log++;
        a.p_b(k % 10);
        k /= 10;
    }

    reverse(all(a));

    for(int i = 1; i < log; i++){

        for(int i = 0; i < 20; i++)
            for(int j = 0; j < 4; j++)
                for(int i1 = 0; i1 < 2; i1++)dp[i][j][i1] = 0;

        for(int j = 1; j < 10; j++)dp[1][1][0]++;

        for(int j = 2; j <= i; j++){
            for(int i1 = 0; i1 < 4; i1++){
                if(i1 < 3)dp[j][i1 + 1][0] += dp[j - 1][i1][0] * 9;
                dp[j][i1][0] += dp[j - 1][i1][0];
            }
        }
        for(int j = 0; j < 4; j++)res += dp[i][j][0];
    }

    for(int i = 0; i < 20; i++)
            for(int j = 0; j < 4; j++)
                for(int i1 = 0; i1 < 2; i1++)dp[i][j][i1] = 0;


    for(int i = 1; i < 10; i++){
        if(i > a[0])break;
        if(i == a[0])dp[1][1][1]++; else dp[1][1][0]++;
    }
    for(int i = 2; i <= log; i++){
        for(int j = 0; j < 10; j++){
            ll kol = 0;
            if(j)kol = 1;
            for(int i1 = 0; i1 < 4; i1++){
                    if(j == a[i - 1])dp[i][i1 + kol][1] += dp[i - 1][i1][1]; else if(j < a[i - 1])dp[i][i1 + kol][0] += dp[i - 1][i1][1];
                    dp[i][i1 + kol][0] += dp[i - 1][i1][0];
            }
        }
    }
    for(int i = 0; i < 4; i++)res += dp[log][i][0] + dp[log][i][1];
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    while(n--){
        ll l, r;
        cin >> l >> r;
        cout << f(r) - f(l - 1) << "\n";
    }
    return 0;
}