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
const ll mod = 1e9 + 7;

ll dp[201][201][201];

void f(ll& a, ll b){a = (a + b) % mod;}

ll z[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll m = s.size();
    vector <ll> a(m + 1);
    dp[0][0][0] = 1;
    for(int i = 1; i <= m; i++){
        if(s[i - 1] == ')')a[i] = -1;else a[i] = 1;
    }
    z[0] = 1e18;
    for(ll i = 1, l = 0, r = 0; i < m; i++){
        if (i <= r)z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])++z[i];
		if (i + z[i] - 1 > r)l = i,  r = i + z[i] - 1;
    }
    for(int i = 1; i <= 2 * n; i++){

        for(int j = 0; j <= 101; j++)
        for(int i1 = 0; i1 <= m; i1++){

            for(int j1 = -1; j1 < 2; j1++)if(j1 != 0){
                ll kol = dp[i - 1][j][i1];
                if(j1 + j >= 0 && kol){
                    if(i1 == m)dp[i][j1 + j][m] = (dp[i][j1 + j][m] + kol) % mod;
                    else if(j1 == a[i1 + 1])dp[i][j1 + j][i1 + 1] = (dp[i][j1 + j][i1 + 1] + kol) % mod;
                    else{
                        for(int jj = i1; jj >= 0; jj--){
                            bool ok = 0;
                            if(!jj)ok = 1;
                            else if(jj == 1 && a[1] == j1)ok = 1;
                            else if(a[jj] == j1 && z[i1 - jj + 1] >= jj - 1)ok = 1;
                            if(ok){
                                dp[i][j1 + j][jj] = (dp[i][j1 + j][jj] + kol) % mod;
                                break;
                            }
                        }
                    }
                }

            }
        }
    }
    cout << dp[2 * n][0][m] << endl;
    return 0;
}