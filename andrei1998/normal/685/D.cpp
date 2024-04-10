#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define lint long long int
using namespace std;

const int NMAX = 100005;
pair <int, int> points[NMAX];

vector <int> all_y;

struct Event {
    int type;
    pair <int, int> point;
} events[2 * NMAX];

bool operator<(const Event &a, const Event &b) {
    return a.point.first < b.point.first;
}

const int INF = 2e9 + 5;

int last[2 * NMAX];
int val[2 * NMAX];

lint ans[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++ i) {
        cin >> points[i].first >> points[i].second;

        all_y.push_back(points[i].second);
        all_y.push_back(points[i].second + k);

        events[2 * i - 1].type = 1;
        events[2 * i - 1].point = points[i];

        events[2 * i].type = -1;
        events[2 * i].point = make_pair(points[i].first + k, points[i].second);
    }

    sort(all_y.begin(), all_y.end());
    all_y.resize(unique(all_y.begin(), all_y.end()) - all_y.begin());

    for (int i = 1; i <= all_y.size(); ++ i)
        last[i] = -INF;

    sort(events + 1, events + 2 * n + 1);
    for (int i = 1; i <= 2 * n; ++ i) {
        int down = lower_bound(all_y.begin(), all_y.end(), events[i].point.second) - all_y.begin() + 1;
        int up = lower_bound(all_y.begin(), all_y.end(), events[i].point.second + k) - all_y.begin() + 1;

        for (int j = down; j < up; ++ j) {
            if (last[j] != -INF)
                ans[val[j]] += 1LL * (events[i].point.first - last[j]) * (all_y[j + 1 - 1] - all_y[j - 1]);

            last[j] = events[i].point.first;
            val[j] += events[i].type;
        }
    }

    for (int i = 1; i <= n; ++ i)
        cout << ans[i] << " \n"[i == n];
    return 0;
}