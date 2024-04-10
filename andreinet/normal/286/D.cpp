#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005;

struct Event {
    int x, time;
    bool type;
    Event() {}
    Event(int _x, int _time, bool _type):
        x(_x), time(_time), type(_type) {}
    bool operator< (const Event& other) const {
        return x < other.x;
    }
};

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<Event> events;
    for (int i = 0; i < m; ++i) {
        int l, r, t;
        cin >> l >> r >> t;
        events.push_back(Event(l, t, true));
        events.push_back(Event(r, t, false));
    }
    sort(events.begin(), events.end());

    vector<int> tourists(n);
    for (int i = 0; i < n; ++i) {
        cin >> tourists[i];
        tourists[i] *= -1;
    }
    reverse(tourists.begin(), tourists.end());
    vector<int64_t> add1(n + 2, 0), add2(n + 2, 0);

    multiset<int> times;
    int last = 0;
    for (const Event& e: events) {
        if (!times.empty() && last < e.x) {
            int left = last;
            int right = e.x;
            int time = *times.begin();
            {
                int pos = upper_bound(tourists.begin(), tourists.end(),
                            right - time) - tourists.begin();
                add1[0] += right;
                add1[pos] -= right;
                add2[0]--;
                add2[pos]++;
                add1[pos] += time;
            }
            {
                int pos = upper_bound(tourists.begin(), tourists.end(),
                            left - time) - tourists.begin();
                add1[0] -= left;
                add1[pos] += left;
                add2[0]++;
                add2[pos]--;
                add1[pos] -= time;
            }
        }
        if (e.type) {
            times.insert(e.time);
        } else {
            times.erase(times.find(e.time));
        }
        last = e.x;
    }

    for (int i = 1; i < n; ++i) {
        add1[i] += add1[i - 1];
        add2[i] += add2[i - 1];
    }

    vector<int64_t> answers(n);
    for (int i = 0; i < n; ++i) {
        answers[n - i - 1] = add1[i] + tourists[i] * add2[i];
    }
    for (int64_t ans: answers) {
        cout << ans << '\n';
    }
}