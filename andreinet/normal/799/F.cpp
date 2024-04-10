#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define SZ(x) ((int) (x).size())
using namespace std;

struct Event {
    int time, type, ind;
    bool operator<(const Event& o) const {
        return time < o.time;
    }
};

class FenwickTree {
public:
    FenwickTree(int n):
        tree(n + 1, 0) {}
    void update(int pos, int value) {
        for (++pos; pos < SZ(tree); pos += pos & -pos) {
            tree[pos] += value;
        }
    }
    int query(int pos) {
        int ret = 0;
        for (++pos; pos > 0; pos -= pos & -pos) {
            ret += tree[pos];
        }
        return ret;
    }
    int query(int left, int right) {
        if (left <= right) {
            return query(right) - query(left - 1);
        } else {
            return 0;
        }
    }
private:
    vector<int> tree;
};

template<class Function>
int64_t solve(int n, int m, vector<pair<int, int>> A, Function f) {
    vector<Event> events;
    for (int i = 0; i < SZ(A); ++i) {
        events.push_back({A[i].first, 1, i});
        events.push_back({A[i].second + 1, -1, i});
    }
    sort(events.begin(), events.end());
    multiset<int> goodPos[2];
    FenwickTree goodPosCnt[] = {FenwickTree(m + 1), FenwickTree(m + 1)};
    for (int i = 1; i <= m; ++i) {
        goodPos[i & 1].insert(i);
        goodPosCnt[i & 1].update(i, 1);
    }
    int invalidMax = 0;
    int firstValid = 0;
    multiset<int> s[2];
    int64_t ans = 0;
    for (int i = 1, j = 0; i <= m; ++i) {
        while (j < SZ(events) && events[j].time <= i) {
            Event e = events[j++];
            if (e.type == 1) {
                s[i & 1].insert(A[e.ind].first);
            } else {
                int x = A[e.ind].first & 1;
                s[x].erase(s[x].find(A[e.ind].first));
                if ((A[e.ind].second - A[e.ind].first + 1) % 2 == 0) {
                    invalidMax = max(invalidMax, A[e.ind].first);
                }
                multiset<int>& cpos = goodPos[(A[e.ind].second ^ 1) & 1];
                FenwickTree& posCnt = goodPosCnt[(A[e.ind].second ^ 1) & 1];
                while (true) {
                    auto it = cpos.lower_bound(A[e.ind].first);
                    if (it != cpos.end() && *it <= A[e.ind].second) {
                        posCnt.update(*it, -1);
                        cpos.erase(it);
                    } else {
                        break;
                    }
                }
                firstValid = max(firstValid, A[e.ind].second);
            }
        }
        int u = i & 1;
        int cntTotal = 0;
        {
            int left = invalidMax + 1;
            int right = i;
            if (s[0].empty() && s[1].empty()) {
                right = min(right, firstValid);
            }
            if (!s[u ^ 1].empty()) {
                auto it = s[u ^ 1].end();
                --it;
                left = max(left, *it);
            }
            cntTotal += goodPosCnt[u].query(left, right);
        }
        {
            int left = invalidMax + 1;
            int right = i;
            if (s[0].empty() && s[1].empty()) {
                right = min(right, firstValid);
            } else {
                if (!s[u ^ 1].empty()) {
                    right = min(right, *s[u ^ 1].begin() - 1);
                }
                if (!s[u].empty()) {
                    right = min(right, *s[u].begin());
                }
            }
            if (!s[u ^ 1].empty()) {
                auto it = s[u ^ 1].end();
                --it;
                left = max(left, *it);
            }
            cntTotal += goodPosCnt[u ^ 1].query(left, right);
        }
        ans += (int64_t) f(i) * cntTotal;
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    int64_t ans = solve(n, m, A, [](int value) -> int{return value;});
    for (int i = 0; i < n; ++i) {
        A[i].first = m - A[i].first + 1;
        A[i].second = m - A[i].second + 1;
        swap(A[i].first, A[i].second);
    }
    ans -= solve(n, m, A, [&m](int value) -> int{return m - value;});
    cout << ans << '\n';
}