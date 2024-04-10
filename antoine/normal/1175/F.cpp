#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 3e5 + 9;

vector<int> elOcc[MxN + 9];
int szOcc[MxN + 9];

struct Range {
    int l, r;

    Range(const int l, const int r) : l(l), r(r) {}

    bool operator<(const Range &other) const {
        return l != other.l ? l < other.l : r < other.r;
    }
};

int n;
set<Range> ranges;

void insertRange(const int l, const int r) {
    auto it = ranges.lower_bound(Range{l, l});
    if (it == ranges.end() || it->r > r) {
        ranges.insert(Range{l, r});
        ++szOcc[r - l + 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        elOcc[x].push_back(i);
    }

    ll ans = 0;
    for (const int i : elOcc[1]) {
        ans++;
        insertRange(i, i);
    }

    for (int elem = 2; !elOcc[elem].empty(); ++elem) {
        vector<int> &indexes = elOcc[elem];
        indexes.insert(indexes.begin(), -1);
        indexes.push_back(n + 1);

        for (int i = 0; i + 1 < (int) indexes.size(); ++i) {
            auto it = ranges.lower_bound({indexes[i] + 1, indexes[i] + 1});

            int mnR = INT_MAX;
            int mxL = INT_MIN;

            while (it != ranges.end() && it->r < indexes[i + 1]) {
                mxL = max(mxL, it->l);
                mnR = min(mnR, it->r);
                szOcc[it->r - it->l + 1]--;
                it = ranges.erase(it);
            }

            if (mnR != INT_MAX) {
                if (i)
                    insertRange(indexes[i], mnR);
                if (indexes[i + 1] <= n)
                    insertRange(mxL, indexes[i + 1]);
            }
        }

        ans += szOcc[elem];
    }

    cout << ans;

    return 0;
}