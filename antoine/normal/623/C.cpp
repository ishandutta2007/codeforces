#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 1e5 + 9;

struct Point {
    int x, y;

    bool operator<(const Point &other) {
        return x < other.x;
    }
};

ll sq(ll x) { return x * x; }

bool f(const ll mid, vector<Point> pts) {
    const int n = (int) pts.size();

    for (int rep = 0; rep < 2; ++rep) {
        vector<int> sufMin(n + 1, 0), sufMax(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            sufMin[i] = min(sufMin[i + 1], pts[i].y);
            sufMax[i] = max(sufMax[i + 1], pts[i].y);
        }

        int preMin = 0, preMax = 0;
        for (int i = 0, j = 0, k = n - 1; i < n && pts[i].x <= 0; ++i) {
            while (j < n && (pts[j].x < 0 || sq(pts[j].x - pts[i].x) <= mid))
                ++j;
            while (pts[k].x > -pts[i].x)
                --k;

            assert(pts[k].x >= 0);

            const int mn = min(preMin, sufMin[min(j - 1, k) + 1]);
            const int mx = max(preMax, sufMax[min(j - 1, k) + 1]);
            if (sq(mx - mn) <= mid && sq(pts[i].x) + sq(max(-mn, mx)) <= mid)
                return true;

            preMin = min(preMin, pts[i].y);
            preMax = max(preMax, pts[i].y);
        }

        reverse(pts.begin(), pts.end());
        for (Point &p : pts)
            p.x = -p.x;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    vector<Point> pts;
    {
        int n;
        cin >> n;
        pts.resize(n);
    }


    ll ans;

    {

        int mnX = INT_MAX;
        int mxX = INT_MIN;
        int mnY = INT_MAX;
        int mxY = INT_MIN;

        for (Point &p : pts) {
            cin >> p.x >> p.y;
            mnX = min(mnX, p.x);
            mxX = max(mxX, p.x);
            mnY = min(mnY, p.y);
            mxY = max(mxY, p.y);
        }
        ans = sq(min(mxX - mnX, mxY - mnY));
    }

    pts.push_back({0, 0});
    sort(pts.begin(), pts.end());

    ll lo = 0;
    ll hi = (ll) 4e16 + 9;

    while (lo < hi) {
        const ll mid = (lo + hi) / 2;
        if (f(mid, pts))
            hi = mid;
        else
            lo = mid + 1;
    }


    cout << min(ans, lo);
    return 0;
}