#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int INF = 0x3f3f3f3f;

struct Query {
    int left, right, index;
    bool operator<(const Query& o) const {
        return right < o.right;
    }
};

class FenwickTree {
public:
    FenwickTree(int n):
        tree(n + 1, INF) {}

    void update(int pos, int value) {
        for (++pos; pos < SZ(tree); pos += pos & -pos) {
            tree[pos] = min(tree[pos], value);
        }
    }

    int query(int pos) {
        int ret = INF;
        for (++pos; pos > 0; pos -= pos & -pos) {
            ret = min(ret, tree[pos]);
        }
        return ret;
    }
private:
    vector<int> tree;
};

struct Segment {
    int left, right, value;
    bool operator<(const Segment& o) const {
        return right < o.right;
    }
};

void getSegments(const vector<int>& a, int left, int right,
                 vector<int>& from,
                 vector<Segment>& segments) {
    if (left == right) {
        return;
    }
    int mid = (left + right) / 2;
    getSegments(a, left, mid, from, segments);
    vector<int> vmin(right - mid, INF);
    priority_queue<pair<int, int>> q;
    {
        set<int> s;
        for (int i = mid + 1; i <= right; ++i) {
            auto it = s.lower_bound(a[i]);
            if (it != s.end()) {
                vmin[i - mid - 1] = min(vmin[i - mid - 1], *it - a[i]);
            }
            if (it != s.begin()) {
                auto it1 = it;
                --it1;
                vmin[i - mid - 1] = min(vmin[i - mid - 1], a[i] - *it1);
            }
            s.insert(it, a[i]);
            q.push(make_pair(-from[i], i));
        }
    }
    {
        multiset<pair<int, int>> s;
        for (int i = mid; i >= left; --i) {
            auto it = s.lower_bound(make_pair(a[i], i));
            if (it == s.end() || it->first != a[i]) {
                s.insert(make_pair(a[i], i));
            }
        }
        for (int i = left; i <= mid; ++i) {
            while (!q.empty() && -q.top().first <= i) {
                int pos = q.top().second;
                q.pop();

                auto it = s.lower_bound(make_pair(a[pos], -1));
                int nPos = -1, diff = INF;
                if (it != s.end()) {
                    diff = it->first - a[pos];
                    nPos = it->second;
                }
                if (it != s.begin()) {
                    --it;
                    if (a[pos] - it->first < diff || (a[pos] - it->first == diff &&
                                it->second > nPos)) {
                        diff = a[pos] - it->first;
                        nPos = it->second;
                    }
                }
                if (diff > vmin[pos - mid - 1]) {
                    nPos = -1;
                }
                if (nPos != -1) {
                    q.push(make_pair(-(nPos + 1), pos));
                    from[pos] = nPos + 1;
                    segments.push_back(Segment{nPos, pos, abs(a[pos] - a[nPos])});
                }
            }
            auto it = s.find(make_pair(a[i], i));
            if (it != s.end()) {
                s.erase(it);
            }
        }
    }
    getSegments(a, mid + 1, right, from, segments);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> from(n, -1);
    vector<Segment> segments;
    getSegments(a, 0, n - 1, from, segments);
    sort(segments.begin(), segments.end());
    int q;
    cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].left >> queries[i].right;
        queries[i].left--;
        queries[i].right--;
        queries[i].index = i;
    }
    sort(queries.begin(), queries.end());
    vector<int> fans(q);
    int pos = 0;
    FenwickTree t(n);
    for (const Query& e: queries) {
        while (pos < SZ(segments) && segments[pos].right <= e.right) {
            t.update(n - segments[pos].left - 1, segments[pos].value);
            pos++;
        }
        fans[e.index] = t.query(n - e.left - 1);
    }
    for (int v: fans) {
        cout << v << '\n';
    }
}