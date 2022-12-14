#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 2e9;
const ll M = 300000;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <int> v[MAXN];

set <int> s;
set <int> :: iterator it;


void dfs(int x){
    s.erase(x);
    for(int i = 0; i + 1 < sz(v[x]); i++){
        it = s.upper_bound(v[x][i]);
        while(it != s.end() && *it < v[x][i + 1]){
            dfs(*it);
            it = s.upper_bound(v[x][i]);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        v[i].p_b(0);
        v[i].p_b(n + 1);
        s.insert(i);
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    for(int i = 1; i <= n; i++)sort(all(v[i]));

    dfs(1);

    if(sz(s))vout("impossible");

    for(int i = 2; i <= n; i++){
        s.insert(i);
    }

    int cnt = 0;

    for(int i = 2; i <= n; i++)if(s.find(i) != s.end()){
        cnt++;
        dfs(i);
    }

    if(cnt <= k && k <= n - sz(v[1]) + 1)vout("possible");
    vout("impossible");

    return 0;
}