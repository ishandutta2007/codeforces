    #include <bits/stdc++.h>
    
    #define f first
    #define s second
    #define pb push_back
    #define mp make_pair
    
    using namespace std;
    
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef pair<long long, long long> pll;
    
    const int N = 400500, inf = 1e9, mod = 998244353;
    
    int sum(int a, int b) {
        a += b;
        if (a >= mod)
            a -= mod;
        return a;
    }
    
    int sub(int a, int b) {
        a -= b;
        if (a < 0)
            a += mod;
        return a;
    }
    
    int mult(int a, int b) {
        return 1ll * a * b % mod;
    }
    
    int bp(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1)
                res = mult(res, a);
            a = mult(a, a);
            b >>= 1;
        }
        return res;
    }
    
    int inv(int x) {
        return bp(x, mod - 2);
    }
    
    int n, k, id[N], val[N * 3], p[N * 3];
    set<pii> st;
    
    int pp(int v) {
        return p[v] == v ? v : p[v] = pp(p[v]);
    }
    
    int get(int l, int r, int x) {
        int v = k++;
        val[v] = x;
        st.insert({x, v});
        while (true) {
            auto it = st.lower_bound({l, -1});
            if (it == st.end() || it->f > r)
                break;
            p[it->s] = v;
            st.erase(it);
        }
        return v;
    }
    
    void solve() {
        for (int i = 0; i < N * 3; i++)
            p[i] = i;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            id[i] = k++;
            val[id[i]] = x;
            st.insert({val[id[i]], id[i]});
        }
        int q;
        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int i, x;
                cin >> i >> x;
                id[i] = k++;
                val[id[i]] = x;
                st.insert({val[id[i]], id[i]});
            }
            if (type == 2) {
                int i;
                cin >> i;
                cout << val[pp(id[i])] << endl;
            }
            if (type == 3) {
                int l, r;
                cin >> l >> r;
                int m = (l + r) >> 1;
                get(l, m, l - 1);
                get(m + 1, r, r + 1);
            }
    //        for (int i = 1; i <= n; i++)
    //            cerr << val[pp(id[i])] << " ";
    //        cerr << endl;
        }
    }
    
    int main() {
    //    freopen("input.txt", "r", stdin);
        ios_base::sync_with_stdio(false);
        int t = 1;
    //    cin >> t;
        for (int i = 1; i <= t; i++) {
    //        cout << "Case #" << i << endl;
            solve();
        }
    }