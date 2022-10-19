#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include<cp/debugger.hpp>
#else 
#define debug(...) 42
#endif

const int RAND_TIMES = 35;
const long long RAND_RANGE = 1e12;

mt19937_64 rng(58);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> vals;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vals.push_back(a[i]);
    };
    vector<vector<int>> queries;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        vector<int> tmp(1, type);
        if (type == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            tmp.push_back(l);
            tmp.push_back(r);
            tmp.push_back(k);
        } else {
            int id, x;
            cin >> id >> x;
            tmp.push_back(id);
            tmp.push_back(x);
            vals.push_back(x);
        }
        queries.push_back(tmp);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }
    for (int i = 0; i < q; i++) {
        if (queries[i][0] == 1) {
            queries[i][2] = lower_bound(vals.begin(), vals.end(), queries[i][2]) - vals.begin();
        }
    }
    vector<long long> bit(n + 1);

    auto update = [&](int k, long long val) {
        for (int i = k; i <= n; i += (i & (-i))) {
            bit[i] += val;
        }
    };

    auto get = [&](int k) {
        long long res = 0;
        for (int i = k; i > 0; i -= (i & (-i))) {
            res += bit[i];
        }
        return res;
    };

    auto get2 = [&](int l, int r) {
        return get(r) - get(l - 1);
    };

    vector<int> res(q, true);
    vector<int> b = a;

    for (int rep = 0; rep < RAND_TIMES; rep++) {
        a = b;
        fill(bit.begin(), bit.end(), 0);
        vector<long long> randVals(vals.size());
        for (long long &e : randVals) {
            e = rng() % RAND_RANGE;
        }
        
        for (int i = 1; i <= n; i++) {
            update(i, randVals[a[i]]);
        }

        // debug(queries);

        for (int i = 0; i < q; i++) {
            if (res[i] == false) continue;
            auto que = queries[i];
            int type = que[0];
            if (type == 1) {
                int id = que[1];
                int y = que[2];
                int x = a[que[1]];
                    update(id, randVals[y] - randVals[x]);
                a[id] = y;
            } else {
                int l = que[1], r = que[2], k = que[3];
                auto foo = get2(l, r);
                if (foo % k) res[i] = false;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        if (queries[i][0] == 2) cout << (res[i] ? "YES\n" : "NO\n");
    }

    return 0;
}