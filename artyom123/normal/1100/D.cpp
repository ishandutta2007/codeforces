#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int INF = 1e9 + 1;

int x, y;
int rook[1000][1000];
map<int, pair<int, int>> ma;

bool go_center() {
    int deltax = 0;
    if (x > 500) {
        deltax = -1;
    } else if (x < 500) {
        deltax = 1;
    }
    int deltay = 0;
    if (y > 500) {
        deltay = -1;
    } else if (y < 500) {
        deltay = 1;
    }
    if (deltax == 0 && deltay == 0) {
        return false;
    }
    if (rook[x + deltax][y + deltay]) {
        deltax = 0;
    }
    x += deltax;
    y += deltay;
    cout << x << " " << y << endl;
    return true;
}

int cnt[2][2];

bool RUN(int deltax, int deltay) {
    int nx = x + deltax;
    int ny = y + deltay;
    if (rook[nx][ny]) {
        nx = x;
    }
    x = nx;
    y = ny;
    cout << x << " " << y << endl;
    return true;
}

int main() {
    cin >> x >> y;
    for (int i = 1; i <= 666; i++) {
        int x, y;
        cin >> x >> y;
        rook[x][y]++;
        ma[i] = {x, y};
    }
    while (go_center()) {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == -1) {
            return 0;
        }
        rook[ma[k].first][ma[k].second]--;
        rook[x][y]++;
        ma[k] = {x, y};
    }
    for (auto &c : ma) {
        int x = c.second.first, y = c.second.second;
        if (x <= 499 && y <= 499) {
            cnt[0][0]++;
            cnt[1][0]++;
            cnt[1][1]++;
            continue;
        }
        if (x <= 499) {
            cnt[0][0]++;
            cnt[0][1]++;
            cnt[1][0]++;
            continue;
        }
        if (y <= 499) {
            cnt[1][1]++;
            cnt[0][1]++;
            cnt[1][0]++;
            continue;
        }
        cnt[0][0]++;
        cnt[0][1]++;
        cnt[1][1]++;
    }
    int deltax = 0, deltay = 0;
    int MX = max(max(cnt[0][0], cnt[0][1]), max(cnt[1][0], cnt[1][1]));
    if (cnt[0][0] == MX) {
        deltax = -1, deltay = 1;
    } else if (cnt[0][1] == MX) {
        deltax = 1, deltay = 1;
    } else if (cnt[1][0] == MX) {
        deltax = -1, deltay = -1;
    } else {
        deltax = 1, deltay = -1;
    }
    while(RUN(deltax, deltay)) {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == -1) {
            return 0;
        }
        rook[ma[k].first][ma[k].second]--;
        rook[x][y]++;
        ma[k] = {x, y};
    }
    return 0;
}