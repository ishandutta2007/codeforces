#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

const int N = 2e5 + 10;
int n, m;
int p[N];
int x[N];

int solve_pref() {
    int ans = 0;
    for (int i = 0; i < n && x[0] > i * 100; ++i) {
        ans += p[i];
    }
    return ans;
}

int solve_suff() {
    int ans = 0;
    for (int i = n - 1; i >= 0 && x[m - 1] < i * 100; --i) {
        ans += p[i];
    }
    return ans;
}

struct Event{
    int x;
    int add;
    Event() = default;
    Event(int _x, int _add) : x(_x), add(_add) {}
    bool operator<(const Event& other) const {
        return x < other.x;
    }
};

int solve(int xl, int xr) {
    int l = xl / 100 + 1;
    int r = (xr - 1) / 100;  
    chkmin(r, n - 1);
    chkmax(l, 0);
    if (l > r) {
        return 0;
    }
    vector<Event> events;
    int cur_ans = 0;
    int ans = 0;
    for (int i = l; i <= r; ++i) {
        if (i * 100 - xl <= xr - i * 100) {
            events.emplace_back(3LL * xl + 1, p[i]);
            events.emplace_back(3LL * (i * 100 + (i * 100 - xl)) - 1, -p[i]);
        } else {
            events.emplace_back(3LL * (i * 100 - (xr - i * 100)) + 1, p[i]);
            events.emplace_back(3LL * xr - 1, -p[i]);
        }
    }
    sort(all(events));
    l = 0;
    while (l < events.size()) {
        r = l;
        while (r < events.size() && events[l].x == events[r].x) {
            cur_ans += events[r].add;
            ++r;
        }
        chkmax(ans, cur_ans);
        l = r;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }   
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
    }
    sort(x, x + m);
    int ans = max(solve_pref(), solve_suff());
    for (int i = 0; i + 1 < m; ++i) {
        chkmax(ans, solve(x[i], x[i + 1]));
    }
    cout << ans << endl;
    return 0;
}