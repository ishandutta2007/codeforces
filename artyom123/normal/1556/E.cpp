 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long 
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

struct Sparse_Table_Min{
    vector<vector<ll>> st;
    Sparse_Table_Min(vector<ll> &a) {
        int n = a.size();
        st.resize(n);
        for (auto &c : st) {
            c.resize(32 - __builtin_clz(n));
        }
        for (int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for (int j = 1; j < 20; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    ll get(int l, int r) {
        int len = r - l;
        int p = 31 - __builtin_clz(len);
        return min(st[l][p], st[r - (1 << p)][p]);
    }
};

struct Sparse_Table_Max{
    vector<vector<ll>> st;
    Sparse_Table_Max(vector<ll> &a) {
        int n = a.size();
        st.resize(n);
        for (auto &c : st) {
            c.resize(32 - __builtin_clz(n));
        }
        for (int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for (int j = 1; j < 20; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    ll get(int l, int r) {
        int len = r - l;
        int p = 31 - __builtin_clz(len);
        return max(st[l][p], st[r - (1 << p)][p]);
    }
};

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> a(n), b(n);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    vector<int> x(n);
    for (int i = 0; i < n; i++) x[i] = a[i] - b[i];
    vector<ll> pr(n + 1);
    for (int i = 1; i <= n; i++) pr[i] = pr[i - 1] + x[i - 1];
    Sparse_Table_Min mn(pr);
    Sparse_Table_Max mx(pr);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (pr[r + 1] - pr[l] != 0) {
            cout << -1 << "\n";
            continue;
        }
        ll x = pr[l];
        ll curmn = mn.get(l + 1, r + 2) - x;
        ll curmx = mx.get(l + 1, r + 2) - x;
        if (curmx > 0) {
            cout << -1 << "\n";
            continue;
        }
        cout << -curmn << "\n";
    }
    return 0;
}