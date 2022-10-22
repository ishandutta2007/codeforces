#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2)
            ans = ans * (li)x % MOD;
        p /= 2;
        x = x * (li)x % MOD;
    }
    return ans;
}

struct segtree {
    int n;
    vector<int> tree;
    
    segtree(int n): n(n), tree(n * 4) {}
    
    void change(int t, int l, int r, int index, int val) {
        if (l == r) {
            tree[t] = val;
            return;
        }
        
        int m = (l + r) / 2;
        if (index <= m)
            change(t * 2 + 1, l, m, index, val);
        else
            change(t * 2 + 2, m + 1, r, index, val);
        tree[t] = max(tree[t * 2 + 1], tree[t * 2 + 2]);
    }
    
    int query(int t, int l, int r, int x, int y) {
        if (x > r || y < l) return 0;
        
        if (l >= x && r <= y) return tree[t];
        
        int m = (l + r) / 2;
        return max(query(t * 2 + 1, l, m, x, y), query(t * 2 + 2, m + 1, r, x, y));
    }
};

vector<int> inc(vector<int> a) {
    int m = *max_element(all(a));
    int n = a.size();
    
    segtree s(m + 1);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        /*
        if (a[i] == 0) {
            ans[i] = 0;
            continue;
        }*/
        
        int now = s.query(0, 0, m, 0, a[i]);
        ans[i] = now + 1;
        s.change(0, 0, m, a[i], now + 1);
    }
    
    return ans;
}

void solve(bool __attribute__((unused)) read) {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(m);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        a[l] += 1;
        if (r + 1 < m)
            a[r + 1] += -1;
    }
    
    for (int i = 1; i < m; ++i)
        a[i] += a[i - 1];
    
    auto one = inc(a);
    reverse(all(a));
    auto two = inc(a);
    reverse(all(two));
    
    int answer = 0;
    for (int i = 0; i < m; ++i)
        answer = max(answer, one[i] + two[i] - 1);
    
    cout << answer << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}