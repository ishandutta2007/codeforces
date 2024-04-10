#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

//#define int li

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    bool read = true;

//#define int unsigned
    int n;
    if (read)
        cin >> n;
    else
        n = 5000;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        if (read)
            cin >> a[i];
        else
            a[i] = 0;

    int nq;
    if (read)
        cin >> nq;
    else
        nq = 100000;

    vector<pair<int, int>> queries(nq);

    for (int i = 0; i < nq; ++i) {
        if (read) {
            cin >> queries[i].first >> queries[i].second;
            --queries[i].first;
            --queries[i].second;
        }
        else {
            queries[i].first = 0;
            queries[i].second = n - 1;
        }
    }

    vector<int> answer(nq);

    const int logMaxN = 13;
    const int maxN = 5005;
    static int d[logMaxN][maxN];

    vector<int> b;
    for (int iter = 0; iter < n; ++iter) {
        for (int i = 0; i < a.size(); ++i)
            d[0][i] = a[i];

        for (int log = 1; log < logMaxN; ++log)
            for (int i = 0; i + (1 << log) - 1 < a.size(); ++i)
                d[log][i] = max(d[log - 1][i], d[log - 1][i + (1 << (log - 1))]);

        auto query = [&](int l, int r) {
            ++r;
            int log = 31 - __builtin_clz(r - l);
            int ans = max(d[log][l], d[log][r - (1 << log)]);
            //cout << "ans " << ans << " exp " << exp << endl;

            //assert(ans == exp);
            return ans;
        };

        for (int i = 0; i < nq; ++i) {
            if (queries[i].second < queries[i].first) {
                continue;
            }

            answer[i] = max(answer[i], query(queries[i].first, queries[i].second));
            --queries[i].second;
        }

        b.resize(a.size() - 1);
        for (int i = 0; i < b.size(); ++i) {
            b[i] = a[i] ^ a[i + 1];
        }
        a = b;
    }

    for (int i = 0; i < nq; ++i)
        if (read)
            cout << answer[i] << "\n";

    return 0;
}