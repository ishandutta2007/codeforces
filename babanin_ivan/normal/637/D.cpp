#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof((x)))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp std::make_pair
#define x first
#define y second

typedef std::pair<int, int> PII;
typedef long long ll;
typedef std::pair<ll, ll> PLL;
typedef long double ld;
typedef std::pair<ld, ld> PLD;
typedef std::pair<double, double> PDD;

using namespace std;


void no() {
    cout << "IMPOSSIBLE" << "\n";
}

const string run = "RUN";
const string jump = "JUMP";

bool check(const vector<PII> &ans, const vector<int> &a, int m, int s, int d) {
    for (const PII &p : ans) {
        if (p.x) {
            if (p.y > d) return false;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i].x) {
            if (i == 0) return false;
            if (ans[i - 1].x) return false;
            if (ans[i - 1].y < s) return false;
        }
    }
    int pos = 0;
    int j = 1;
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i].x) {
            pos += ans[i].y;
            while (j < a.size() && a[j] < pos) {
                ++j;
            }
        } else {
            pos += ans[i].y;
        }
        if (j < a.size() && a[j] <= pos) return false;
    }
    return pos == m;
}

void solve() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.push_back(-1);
    sort(all(a));
    vector<PII> segs;
    for (int i = 0; i + 1 < a.size(); ++i) {
        if (a[i + 1] - a[i] >= s + 2) {
            segs.push_back(mp(a[i] + 1, a[i + 1] - 1));
        }
    }
    segs.push_back(mp(a.back() + 1, m));
    if (segs[0].x != 0) {
        no();
        return;
    }

    vector<PII> ans;
    for (int i = 0; i + 1 < segs.size(); ++i) {
        if (segs[i + 1].x - segs[i].y > d) {
            no();
            return;
        }
        ans.push_back(mp(0, segs[i].y - segs[i].x));
        ans.push_back(mp(1, segs[i + 1].x - segs[i].y));
    }
    if (segs.back().y - segs.back().x > 0) {
        ans.push_back(mp(0, segs.back().y - segs.back().x));
    }
    //assert(check(ans, a, m, s, d));

    for (const PII &p : ans) {
        if (p.x) {
            cout << jump << " " << p.y << "\n";
        } else {
            cout << run << " " << p.y << "\n";
        }
    }
}



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}