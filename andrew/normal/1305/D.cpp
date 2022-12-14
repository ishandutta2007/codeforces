#include <bits/stdc++.h>
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("no-stack-protector")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define pci pair<int, char>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pdd pair<ld, ld>
#define ft first
#define sd second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<class T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N = 100100;
const int M = 10;
const int oo = 2e9;
const ll OO = 1e18;
const int md = int(1e9) + 7;
const int K = 60;
const ld E = 1e-9;
vector<int> g[N];
int n, len[N], nom[N];
bool mrk[N];

void dfs(int v, int p){

    len[v] = 0; nom[v] = v;

    for (int u : g[v]){
        if (u == p) continue;
        if (mrk[u]) continue;

        dfs(u, v);

        if (len[v] < len[u] + 1){
            len[v] = len[u] + 1;
            nom[v] = nom[u];
        }
    }
}

int main() {
#ifdef _LOCAL
//    freopen("in.txt","r",stdin); // freopen("output.txt","w",stdout);
#else
//    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif

    srand(time(0));

    cin >> n;

    for (int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        x--; y--;

        g[x].PB(y);
        g[y].PB(x);
    }

    int lca = 0;

    for (;;){

        dfs(lca, -1);

        if (len[lca] == 0){
            cout << "! " << lca + 1 << endl;
            return 0;
        }

        int cur = nom[lca];

        dfs(cur, -1);

        lca = nom[cur];

        cout << "? " << cur + 1 << " " << lca + 1 << endl;

        int gt; cin >> gt;
        gt--;

        if (gt == cur || gt == lca){

            cout << "! " << gt + 1 << endl;
            return 0;
        }

        mrk[cur] = mrk[lca] = 1;

        lca = gt;
    }

    return 0;
}