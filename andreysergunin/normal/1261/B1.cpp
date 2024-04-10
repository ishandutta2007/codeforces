#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

struct Query {
    int k, pos, id;
};

bool operator<(const Query &a, const Query &b) {
    return tie(a.k, a.pos, a.id) < tie(b.k, b.pos, b.id);
}

void solve() {
    int n;
    cin >> n;
    vector<pii> arr(n);
    vector<int> init(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        init[i] = arr[i].first;
        arr[i].second = -i;
    }
    sort(all(arr));

    ordered_set setik;

    int q;
    cin >> q;

    vector<Query> queries(q);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].k;
        cin >> queries[i].pos;
        --queries[i].pos;
        queries[i].id = i;;
    }
    sort(all(queries));
    vector<int> res(q);

    int i = 0;
    for (int k = 1; k <= n; ++k) {
        setik.insert(-arr[n - k].second);
        while (i < sz(queries) && k == queries[i].k)  {
            res[queries[i].id] = *setik.find_by_order(queries[i].pos);
            ++i;
        }
    }

    for (int i : res) {
        cout << init[i] << endl;
    }
    cout << endl;
}

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}