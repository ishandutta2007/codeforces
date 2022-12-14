#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define pil pair<int, ll>

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

ll dp[501][5110];
ll a[MAXN], b[MAXN], h[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, k;
    cin >> n >> k;
    ll m = n * k;
    while(m--){
        ll x;
        cin >> x;
        a[x]++;
    }

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        b[x]++;
    }
    for(int i = 1; i <= k; i++)cin >> h[i];

    ll N = 1e5, ans = 0;
    for(int i = 1; i <= N; i++)if(b[i]){
        ll nn = min(a[i], k * b[i]);
        for(int i1 = 0; i1 <= b[i]; i1++)
            for(int j1 = 0; j1 <= nn; j1++)dp[i1][j1] = 0;
        for(int i1 = 1; i1 <= b[i]; i1++){
            for(int j1 = 0; j1 <= nn; j1++){
                for(int j = 0; j <= k; j++){
                    dp[i1][j1 + j] = max(dp[i1][j1 + j], dp[i1 - 1][j1] + h[j]);
                }
            }
        }
        ans += dp[b[i]][nn];
    }
    cout << ans << "\n";
    return 0;
}