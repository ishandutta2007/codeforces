#include <bits/stdc++.h>

using namespace std;

#define int long long

void build(vector <int> &tree, vector <int> a, int v, int l, int r) {
    if (l == r) {
        tree[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(tree, a, 2 * v, l, m);
    build(tree, a, 2 * v + 1, m + 1, r);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

int get(vector <int> &tree, int v, int l, int r, int a, int b) {
    if (l > b || a > r) {
        return 10000000;
    }
    if (a <= l && r <= b) {
        return tree[v];
    }
    int m = (l + r) / 2;
    return min(get(tree, 2 * v, l, m, a, b), get(tree, 2 * v + 1, m + 1, r, a, b));
}

signed main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int q = (int)(1 << (int)(ceil(log2(n))));
        vector <int> a(q);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        vector <int> st;
        vector <bool> ans(n, false);
        st.push_back(-1);
        for (int j = 0; j < n; ++j) {
            if (st.back() == -1) {
                st.push_back(j);
            }
            else if (a[j] < a[st.back()]) {
                while (st.back() != -1 && a[j] < a[st.back()]) {
                    ans[st.back()] = true;
                    st.pop_back();
                }
                st.push_back(j);
            }
            else {
                st.push_back(j);
            }
        }
        int res = 0;
        for (int k = 0; k < n; ++k) {
            res += ans[k];
        }
        cout << res << "\n";
    }
}