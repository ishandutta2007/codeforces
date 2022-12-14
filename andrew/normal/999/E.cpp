#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define next ku
#define all(x) x.begin(),x.end()

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
bool fl[5001][5001];
ll xe;
ll ans[MAXN];
vector <ll> v[MAXN];
ll n, m, k;
void dfs(ll x){
                         if(fl[xe][x])return;
                         fl[xe][x] = 1;
                         ans[xe]++;
                         for(auto i : v[x])dfs(i);
}
void add(ll x){
                         for(int i = 1; i <= n; i++)if(fl[i][x]){
                                                  fl[i][x] = 0;
                                                  ans[i]--;
                         }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    
    cin >> n >> m >> k;
    while(m--){
                             ll a, b;
                             cin >> a >> b;
                             v[a].p_b(b);
    }
    for(int i = 1; i <= n; i++){
                             xe = i;
                             dfs(i);
    }
    ll res = 0;
    for(int i = 1; i <= n; i++)if(fl[k][i])add(i);
    while(1){
                             ll mxj = 1;
                             for(int i = 2; i <= n; i++)if(ans[i] > ans[mxj])mxj = i;
                             if(!ans[mxj])break;
                             res++;
                             for(int i = 1; i <= n; i++)if(fl[mxj][i])add(i);
    }
    return cout << res << "\n", 0;
 }