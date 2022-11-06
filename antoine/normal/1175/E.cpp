#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


typedef pair<int, int> pii;


void filter(vector<pii> &ranges) {
    vector<pii> res;
    for (const pii &p : ranges) {
        if (!res.empty() && p.second <= res.back().second)
            continue;
        if (!res.empty() && res.back().first == p.first)
            res.back().second = p.second;
        else
            res.push_back(p);
    }

    ranges = move(res);
}

bool compBySecond(const pii &p1, const pii &p2) {
    return p1.second < p2.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pii> ranges(n);
    for (pii &p : ranges)
        cin >> p.first >> p.second;

    sort(ranges.begin(), ranges.end());
    filter(ranges);


    n = (int) ranges.size();
    vector<vector<int>> nxt;
    nxt.resize(n);
    for (int i = n - 2; i >= 0; --i) {
        {
            int j = lower_bound(ranges.begin() + i + 1, ranges.end(), pii{ranges[i].second + 1, -1}) - ranges.begin();
            if (--j == i)
                continue;
            nxt[i].push_back(j);
        }
        for (int k = 1;; ++k) {
            const vector<int> &v = nxt[nxt[i][k - 1]];
            if ((int) v.size() <= k - 1)
                break;
            nxt[i].push_back(v[k - 1]);
        }
    }

    while (m--) {
        int l, r;
        cin >> l >> r;

        int i = lower_bound(ranges.begin(), ranges.end(), pii{l + 1, -1}) - ranges.begin();
        if (!i) {
            // cerr << "2\n";
            cout << "-1\n";
            continue;
        }
        --i;


        int ans = 1;

        for (int k = 100;; --k) {
            k = min(k, (int) nxt[i].size() - 1);
            if (k < 0)
                break;
            const int j = nxt[i][k];
            if (ranges[j].second < r) {
                ans += 1 << k;
                i = j;
            }
        }
        if (ranges[i].second < r && !nxt[i].empty()) {
            ++ans;
            i = nxt[i][0];
        }
        if (ranges[i].second < r)
            ans = -1;

        cout << ans << '\n';
    }

    return 0;
}