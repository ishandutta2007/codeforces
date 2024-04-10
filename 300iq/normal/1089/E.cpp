#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int, int> ipair;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    //freopen("a.in", "r", stdin);
#endif
    int k;
    cin >> k;
    ++k;

    vector<ipair> a = {{0, 0}};
    auto go = [&](int n, int x, int y) {
        for (int i = 0; i < n; ++i)
            a.push_back({a.back().first + x, a.back().second + y});
    };
    go(7, 1, 0);
    a.push_back({7, 1});
    a.push_back({0, 1});
    go(6, 0, 1);
    go(1, 1, 0);
    go(6, 0, -1);
    go(1, 1, 0);
    go(6, 0, 1);
    go(1, 1, 0);
    go(6, 0, -1);
    go(1, 1, 0);
    go(6, 0, 1);
    go(1, 1, 0);
    go(6, 0, -1);
    go(1, 1, 0);
    go(6, 0, 1);
    go(1, 1, 0);
    go(5, 0, -1);

    static bool vis[8][8];
    ipair prv = {0, 0};
    vector<ipair> b(a.begin(), a.begin() + k - 1);
    for (ipair x : b)
        vis[x.first][x.second] = 1;
    ipair l = b.back();
    bool done = false;
    for (int x = 0; x < 8; ++x)
        if (!vis[x][l.second] && x != 0 && l.second != 0) {
            done = 1;
            b.push_back({x, l.second});
            break;
        }
    for (int x = 0; !done && x < 8; ++x)
        if (!vis[l.first][x] && l.first != 0 && x != 0) {
            done = 1;
            b.push_back({l.first, x});
            break;
        }

    auto print = [&](ipair w) {
        if (w.X == 7)
            w.X = b.back().X;
        else if (w.X == b.back().X)
            w.X = 7;
        if (w.Y == 7)
            w.Y = b.back().Y;
        else if (w.Y == b.back().Y)
            w.Y = 7;
        cout << (char)(w.X + 'a') << w.Y + 1 << " ";
    };
    for (ipair w : b)
        print(w);
    cout << "\n";
}