#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 111

const int defX[4] = {-1, 1, 0, 0};
const int defY[4] = {0, 0, -1, 1};

int n, m, i, j, x, y;
char data[maxN][maxN];

bool ud, lr;
vector< pair<int, int> > steps;

pair<int, int> ask(char c) {
    printf("%c\n", c);
    fflush(stdout);
    int a, b;
    scanf("%d%d", &a, &b);
    if (data[a][b] == 'F') exit(0);
    return mp(a, b);
}

void move_down() {
    auto act = (ud ? ask('U') : ask('D') );
    x = act.first;
    y = act.second;
}

void move_up() {
    auto act = (ud ? ask('D') : ask('U') );
    x = act.first;
    y = act.second;
}

void move_left() {
    auto act = (lr ? ask('R') : ask('L') );
    x = act.first;
    y = act.second;
}

void move_right() {
    auto act = (lr ? ask('L') : ask('R') );
    x = act.first;
    y = act.second;
}

bool dfs(int x, int y) {
    if (data[x][y] == 'F') {
        steps.pb(mp(x, y));
        return true;
    }

    data[x][y] = '*';
    for (int i = 0; i < 4; i++) {
        int xx = x + defX[i];
        int yy = y + defY[i];

        if (data[xx][yy] == '*') continue;
        if (dfs(xx, yy)) {
            steps.pb(mp(x, y));
            return true;
        }
    }

    return false;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &m);
    for (i = 1; i <= n; i++) scanf("%s", data[i] + 1);

    if (data[2][1] != '*') {
        auto act = ask('U');
        if (act == mp(1, 1))
            ud = false;
        else
            ud = true;
        x = act.first; y = act.second;

        if (x == 2)
            move_up();

        for (i = 1; i <= n; i++) {
            while (x != i) move_down();
            if (data[x][y + 1] != '*') break;
        }

        act = ask('L');
        if (act == mp(x, y))
            lr = false;
        else
            lr = true;
        x = act.first; y = act.second;
    } else {
        auto act = ask('L');
        if (act == mp(1, 1))
            lr = false;
        else
            lr = true;
        x = act.first; y = act.second;

        if (y == 2)
            move_left();


        for (i = 1; i <= m; i++) {
            while (y != i) move_right();
            if (data[x + 1][y] != '*') break;
        }

        act = ask('U');
        if (act == mp(x, y))
            ud = false;
        else
            ud = true;
        x = act.first; y = act.second;
    }

    for (i = 1; i <= n; i++) data[i][0] = data[i][m + 1] = '*';
    for (i = 1; i <= m; i++) data[0][i] = data[n + 1][i] = '*';

    dfs(x, y);
    reverse(steps.begin(), steps.end());

    for (i = 1; i < steps.size(); i++) {
        if (steps[i - 1].first + 1 == steps[i].first)
            move_down();

        if (steps[i - 1].first - 1 == steps[i].first)
            move_up();

        if (steps[i - 1].second + 1 == steps[i].second)
            move_right();

        if (steps[i - 1].second - 1 == steps[i].second)
            move_left();
    }

    return 0;
}