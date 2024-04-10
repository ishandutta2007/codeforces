#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 50005;

int n, r[MN][5];

bool sup(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) if (r[x][i] < r[y][i]) cnt++;
    return cnt >= 3;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 5; j++) cin >> r[i][j];
        }
        int win = 1;
        for (int i = 2; i <= n; i++) {
            if (sup(i, win)) win = i;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += sup(win, i);
        }
        if (cnt == n - 1) printf("%lld\n", win);
        else printf("-1\n");
    }

    return 0;
}