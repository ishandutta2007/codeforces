#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

struct Segment {
    int d, x, y;
    Segment() {}
    Segment(int _d, int _x, int _y):
        d(_d), x(_x), y(_y) {}

    bool operator< (const Segment& other) const {
        return (y < other.y) || (y == other.y && x > other.x);
    }
};

struct Event {
    int time, pos, type;
    Event() {}
    Event(int _time, int _pos, int _type):
        time(_time), pos(_pos), type(_type) {}
    bool operator < (const Event& other) const {
        return time < other.time;
    }
};

class FenwickTree {
public:
    FenwickTree(int _n):
        tree(vector<int>(_n, 0)), n(_n) {}
    void update(int pos, int val) {
        for (++pos; pos <= n; pos += pos & -pos)
            tree[pos - 1] += val;
    }
    int query(int pos) {
        int ret = 0;
        for (++pos; pos > 0; pos -= pos & -pos)
            ret += tree[pos - 1];
        return ret;
    }
    int query(int left, int right) {
        if (left > right) return 0;
        return query(right) - query(left - 1);
    }
private:
    vector<int> tree;
    int n;
};

int search(const vector<vector<Segment>>& a, int d) {
    int pos = -1, step;
    for (step = 1; step < SZ(a); step <<= 1);
    for (; step > 0; step >>= 1) {
        if (pos + step < SZ(a) && a[pos + step][0].d < d)
            pos += step;
    }
    return pos + 1;
}

vector<vector<Segment>> merge(vector<Segment> segs) {
    auto cmp = [](const Segment& a, const Segment& b) -> bool {
            return a.d < b.d;
        };
    sort(segs.begin(), segs.end(), cmp);
    vector<vector<Segment>> intervals;
    int n = SZ(segs);
    for (int i = 0, j; i < n; i = j) {
        for (j = i + 1; j < n && segs[j].d == segs[i].d; ++j);
        intervals.push_back(vector<Segment>(
                segs.begin() + i,  segs.begin() + j));
    }
    for (int i = 0; i < SZ(intervals); ++i) {
        vector<Segment>& a = intervals[i];
        sort(a.begin(), a.end());
        vector<Segment> b;
        for (Segment e: a) {
            while (!b.empty() && b.back().y >= e.x - 1) {
                e.x = min(b.back().x, e.x);
                b.pop_back();
            }
            b.push_back(e);
        }
        a = b;
    }
    return intervals;
}

vector<Segment> concat(const vector<vector<Segment>>& a) {
    vector<Segment> result;
    for (const vector<Segment>& e: a) {
        result.insert(result.end(), e.begin(), e.end());
    }
    return result;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<Segment> horizontal, vertical;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2 < x1) swap(x1, x2);
        if (y2 < y1) swap(y1, y2);
        if (y1 == y2) {
            horizontal.push_back(Segment(y1, x1, x2));
        } else {
            vertical.push_back(Segment(x1, y1, y2));
        }
    }

    vector<vector<Segment>> intervals = merge(horizontal);
    int64_t ans = 0;

    vector<Event> events;
    for (int i = 0; i < SZ(intervals); ++i) {
        for (const Segment& e: intervals[i]) {
            ans += e.y - e.x + 1;
            events.push_back(Event(e.x, i, 1));
            events.push_back(Event(e.y + 1, i, -1));
        }
    }
    sort(events.begin(), events.end());
    events.push_back(Event(1e9 + 7, 0, 0));

    FenwickTree tree(SZ(intervals));
    vertical = concat(merge(vertical));
    int pos = 0;
    for (const Event& e: events) {
        while (pos < SZ(vertical) && vertical[pos].d < e.time) {
            Segment c = vertical[pos++];
            ans += c.y - c.x + 1;
            int p1 = search(intervals, c.x);
            int p2 = search(intervals, c.y + 1) - 1;
            
            if (!(p2 < 0 || p1 >= SZ(intervals))) {
                ans -= tree.query(p1, p2);
            }
        }
        tree.update(e.pos, e.type);
    }

    cout << ans << '\n';
}