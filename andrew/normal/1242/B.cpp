#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN];
set <ll> s;
ll r, n, m, a[MAXN], b[MAXN];
set <ll> :: iterator it;
void dfs(ll x){
    b[x] = 1;
    a[r]++;
    s.erase(x);
    for(int i = 0; i < sz(v[x]) - 1; i++){
        ll l = v[x][i] + 1, r = v[x][i+1] - 1;
        if(l <= r){
            it = s.lower_bound(l);
            while(it != s.end() && (*it) <= r){
                dfs(*it);
                it = s.lower_bound(l);
            }
        }
    }
    return;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    cin >> n >> m;

    for(int i = 1; i <= n; i++)v[i].p_b(0);

    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    for(int i = 1; i <= n; i++)sort(all(v[i]));

    for(int i = 1; i <= n; i++)v[i].p_b(n+1);
    for(int i = 1; i <= n; i++)s.insert(i);

    for(int i = 1; i <= n; i++)if(!b[i]){
        r++;
        dfs(i);
    }
    cout << r - 1 << "\n";
    return 0;
}