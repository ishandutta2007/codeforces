#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int c[222222];
int a[222222];
vector<int> st;
int used[222222];
int tu = 1;
int d[222222];

int dfs(int v) {
    if (d[v] != -1) {
        return d[v];
    }
    used[v] = tu;
    st.push_back(v);
    if (used[a[v]] != tu) {
        d[v] = dfs(a[v]);
        st.pop_back();
        return d[v];
    }

    int ans = c[v];
    int ai = v;
    for (int i = st.size() - 1; ; i--) {
        int x = st[i];
        if (c[x] < ans) {
            ans = c[x];
            ai = x;
        }
        if (x == a[v]) {
            break;
        }
    }
    st.pop_back();
    return d[v] = ai;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(d, -1, sizeof(d));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }

    set<int> tp;

    for (int i = 0; i < n; i++) {
        tu++;
        tp.insert(dfs(i));
    }

    int ans = 0;
    for (int i : tp) {
        ans += c[i];
    }

    cout << ans;

    return 0;
}//guexuq