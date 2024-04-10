#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

//#define int li

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    bool read = true;

    int n;
    if (read)
        cin >> n;
    else
        n = 2000;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        if (read)
            cin >> a[i] >> b[i];
        else {
            a[i] = 1;
            b[i] = 9;
        }
    }

    const int maxN = 2005;

    // cur + all others
    static int d[10][10][10][10][10], d2[10][10][10][10][10];

    const int INF = 1e9;

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < 10; ++k)
                for (int l = 0; l < 10; ++l)
                    for (int t = 0; t < 10; ++t)
                    d[i][j][k][l][t] = INF;

    d[1][0][0][0][0] = 0;

    auto relax = [&]() {
        for (int i = 1; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                for (int k = j; k < 10; ++k)
                    for (int l = k; l < 10; ++l)
                        for (int t = l; t < 10; ++t) {
            int cur = d[i][j][k][l][t];
            if (cur == INF)
                continue;

            for (int di = -1; di <= 1; di += 2) {
                if (i + di < 1 || i + di >= 10) continue;

                array<int, 4> nums = {{j, k, l, t}};
                for (int& x: nums) {
                    if (x == i + di) x = 0;
                }
                sort(nums.begin(), nums.end());

                int& to = d[i + di][nums[0]][nums[1]][nums[2]][nums[3]];
                to = min(to, cur + 1);
            }
        }
    };

    int answer = INF;

    for (int curGuy = 0; curGuy <= n; ++curGuy) {
        //cout << curGuy << endl;

        for (int t = 0; t < 20; ++t)
            relax();

        memcpy(d2, d, sizeof(d2));

        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                for (int k = j; k < 10; ++k)
                    for (int l = k; l < 10; ++l)
                        for (int t = l; t < 10; ++t) {
                            if (curGuy == n && j == 0 && k == 0 && l == 0 && t == 0) {
                                answer = min(answer, d[i][j][k][l][t]);
                            }

                            d[i][j][k][l][t] = INF;
                        }

        if (curGuy == n) {
            break;
        }

        for (int i = 1; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                for (int k = j; k < 10; ++k)
                    for (int l = k; l < 10; ++l)
                        for (int t = l; t < 10; ++t) {
                            int& cur = d2[i][j][k][l][t];
                            if (cur == INF) continue;

                            if (j == 0 && i == a[curGuy]) {
                                array<int, 4> to = {{ b[curGuy], k, l, t }};
                                sort(all(to));
                                d[i][to[0]][to[1]][to[2]][to[3]] = cur;
                            }
                        }
    }

    answer += 2 * n;
    cout << answer << endl;

    return 0;
}