#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , m , par[MAXN] , sz[MAXN];

int Find(int v){
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(int v , int u){
    v = Find(v) , u = Find(u);
    if(v == u)  return;
    if(sz[v] < sz[u])   swap(v , u);
    par[u] = v;
    sz[v] += sz[u];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fill(par , par + MAXN , -1);
    fill(sz , sz + MAXN , 1);

    cin >> n >> m;
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        vector<int> vec;
        int k;
        cin >> k;
        for(int j = 0 ; j < k ; j++){
            int x; cin >> x;
            vec.push_back(x);
        }
        if(k == 1)  vec.push_back(m + 1);
        int v = vec[0] , u = vec[1];
        if(Find(v) == Find(u))  continue;
        Union(v , u);
        ans.push_back(i + 1);
    }
    cout << poww(2 , SZ(ans) , MOD) << sep << SZ(ans) << endl;
    for(int i : ans)    cout << i << sep;

    return 0;
}
/*

*/