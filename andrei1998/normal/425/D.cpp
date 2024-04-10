#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <utility>

using namespace std;

const int NMAX = 100005;

pair <int, int> points[NMAX];

const int VALMAX = 1000005;
vector <int> xs[2 * VALMAX];
vector <int> ys[2 * VALMAX];

const int MOD = 666013;
list <pair <int, int> > hs[MOD + 5];

void add(const pair <int, int> &p) {
    int b = (1ll * VALMAX * p.first + p.second) % MOD;
    hs[b].push_back(p);
}

bool count(const pair <int, int> &p) {
    int b = (1LL * VALMAX * p.first + p.second) % MOD;
    for (list <pair <int, int> > :: iterator it = hs[b].begin(); it != hs[b].end(); ++ it)
        if (*it == p)
            return true;
    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        cin >> points[i].first >> points[i].second;

        points[i].first += VALMAX;
        points[i].second += VALMAX;

        xs[points[i].first].push_back(points[i].second);
        ys[points[i].second].push_back(points[i].first);
        add(points[i]);
    }

    for (int i = 0; i < 2 * VALMAX; ++ i) {
        sort(xs[i].begin(), xs[i].end());
        sort(ys[i].begin(), ys[i].end());
    }

    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        int pos_xs = lower_bound(xs[points[i].first].begin(), xs[points[i].first].end(), points[i].second) - xs[points[i].first].begin();
        int pos_ys = lower_bound(ys[points[i].second].begin(), ys[points[i].second].end(), points[i].first) - ys[points[i].second].begin();

        if (xs[points[i].first].size() - pos_xs < ys[points[i].second].size() - pos_ys) {
            for (int j = pos_xs + 1; j < xs[points[i].first].size(); ++ j) {
                int l = xs[points[i].first][j] - points[i].second;
                if (l > ys[points[i].second].back() - points[i].first)
                    break;
                ans += (count(make_pair(points[i].first + l, points[i].second)) && count(make_pair(points[i].first + l, points[i].second + l)));
            }
        }
        else {
            for (int j = pos_ys + 1; j < ys[points[i].second].size(); ++ j) {
                int l = ys[points[i].second][j] - points[i].first;
                if (l > xs[points[i].first].back() - points[i].second)
                    break;
                ans += (count(make_pair(points[i].first, points[i].second + l)) && count(make_pair(points[i].first + l, points[i].second + l)));
            }
        }
    }

    cout << ans << '\n';
    return 0;
}