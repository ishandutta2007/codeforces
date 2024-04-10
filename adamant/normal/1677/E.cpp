#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define int int64_t
#define _ << ' ' <<
#define all(x) begin(x), end(x)

using namespace std;
using namespace __gnu_pbds;

template<class key, class val = null_type, class cmp = less<key>>
using ordered_set = tree<key, val, cmp, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> lwb(int *a, int n) {
    vector<int> res(n);
    vector<int> st = {-1};
    for(int i = 0; i < n; i++) {
        while(st.back() != -1 && a[st.back()] < a[i]) {
            st.pop_back();
        }
        res[i] = st.back();
        st.push_back(i);
    }
    return res;
}

const int maxn = 2e5 + 42;

int A[4 * maxn], B[4 * maxn];
int smA[4 * maxn], smB[4 * maxn];

void add(int a, int b, int da, int db, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        A[v] += da;
        B[v] += db;
        smA[v] += da * (r - l);
        smB[v] += db * (r - l);
    } else if(r <= a || b <= l) {
        return;
    } else {
        int m = (l + r) / 2;
        add(a, b, da, db, 2 * v, l, m);
        add(a, b, da, db, 2 * v + 1, m, r);
        smA[v] = smA[2 * v] + smA[2 * v + 1] + A[v] * (r - l);
        smB[v] = smB[2 * v] + smB[2 * v + 1] + B[v] * (r - l);
    }
}

pair<int, int> get(int a, int b, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        return {smA[v], smB[v]};
    } else if(r <= a || b <= l) {
        return {0, 0};
    } else {
        int m = (l + r) / 2;
        auto [A0, B0] = get(a, b, 2 * v, l, m);
        auto [A1, B1] = get(a, b, 2 * v + 1, m, r);
        int inter = min(r, b) - max(l, a);
        return {
            A0 + A1 + inter * A[v],
            B0 + B1 + inter * B[v]
        };
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> divs[n + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            divs[j].push_back(i);
        }
    }
    int p[n];
    int pos[n + 1];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    auto L = lwb(p, n);
    reverse(p, p + n);
    auto R = lwb(p, n);
    reverse(p, p + n);
    reverse(all(R));
    for(auto &it: R) {
        it = n - it - 1;
    }
    
    vector<tuple<int, int, int, int>> to_add[n + 1];
    
    auto add_rec = [&](int l1, int l2, int r1, int r2) {
        //cerr << l1 << ' ' << l2 << ' ' << r1 << ' ' << r2 << "\n";
        to_add[l1].emplace_back(r1, r2, -l1, 1); // a + b*r1 += 1
        to_add[l2].emplace_back(r1, r2, l2, -1); // a + b*r2 -= 1
    };
    
    for(int i = 0; i < n; i++) {
        vector<tuple<int, int, int, int>> recs;
        for(auto it: divs[p[i]]) {
            if(it * it != p[i]) {
                int A = pos[it];
                int B = pos[p[i] / it];
                int C = i;
                int L2 = min({A, B, C});
                int R1 = max({A, B, C});
                if(L2 - L[i] > 0 && R[i] - R1 > 0) {
                    recs.emplace_back(L[i] + 1, L2 + 1, -R1, R[i]);
                }
            }
        }
        sort(all(recs));
        vector<tuple<int, int, int, int>> trim;
        for(auto it: recs) {
            get<2>(it) = -get<2>(it);
            while(!trim.empty() && get<2>(trim.back()) >= get<2>(it)) {
                trim.pop_back();
            }
            if(!trim.empty()) {
                get<0>(it) = get<1>(trim.back());
            }
            trim.push_back(it);
        }
        for(auto it: trim) {
            apply(add_rec, it);
        }
    }
    
    int x[q], y[q];
    vector<int> ans(q);
    vector<int> qadd[n + 1], qsub[n + 1];
    for(int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        qadd[y[i]].push_back(i);
        qsub[x[i]].push_back(i);
    }
    
    for(int i = 0; i <= n; i++) {
        //cout << i << ":" << endl;
        for(auto it: qadd[i]) {
            auto [a0, b0] = get(x[it], y[it]);
            //cout << "gadd " << x[it] _ y[it] _ a0 _ b0 << endl;
            ans[it] += a0 + b0 * i;
        }
        for(auto it: qsub[i]) {
            auto [a0, b0] = get(x[it], y[it]);
            //cout << "gsub " << x[it] _ y[it] _ a0 _ b0 << endl;
            ans[it] -= a0 + b0 * i;
        }
        for(auto [a, b, da, db]: to_add[i]) {
            //cout << "add " _ a _ b _ da _ db << endl;
            add(a, b, da, db);
        }
    }
    
    for(auto &it: ans) {
        cout << it << "\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; 
    t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}