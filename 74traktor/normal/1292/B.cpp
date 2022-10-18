#include<bits/stdc++.h>

using namespace std;

#define int long long
int maxn = 1e18;

inline int f(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x0, y0, ax, ay, bx, by, xs, ys, T, ans = 0;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> T;
    vector < pair < int, int > > Q;
    Q.push_back({x0, y0});
    while (1) {
        int go_x = Q.back().first, go_y = Q.back().second;
        if (go_x > maxn / (double)ax) break;
        if (go_y > maxn / (double)ay) break;
        go_x = go_x * ax + bx;
        go_y = go_y * ay + by;
        Q.push_back({go_x, go_y});
    }
    for (int j = 0; j < (int)Q.size(); ++j) {
        for (int z = j; z < (int)Q.size(); ++z) {
            for (int t = j; t <= z; ++t) {
                int dist1 = f(xs, ys, Q[t].first, Q[t].second) + f(Q[j].first, Q[j].second, Q[z].first, Q[z].second) + f(Q[t].first, Q[t].second, Q[j].first, Q[j].second);
                int dist2 = f(xs, ys, Q[t].first, Q[t].second) + f(Q[j].first, Q[j].second, Q[z].first, Q[z].second) + f(Q[t].first, Q[t].second, Q[z].first, Q[z].second);
                if (min(dist1, dist2) <= T) ans = max(ans, z - j + 1);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}