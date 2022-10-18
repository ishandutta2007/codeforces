#include <bits/stdc++.h>

using namespace std;

int inf = 1e9;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, b, w;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> b >> w;
        if (b == w) {
            cout << "YES" << '\n';
            for (int j = 1; j <= b + w; ++j) cout << 1 << " " << j << '\n';
        }
        else if (b > w) {
            vector < pair < int, int > > out;
            out.push_back({inf / 2, inf / 2});
            w--;
            int x = inf / 2, y = inf / 2;
            int cur = 1;
            bool f = false;
            while (1) {
                if (cur == 1) {
                    out.push_back({x - 1, y});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x + 1, y});;
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x, y - 1});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x, y + 1});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x, y + 2});
                    w--;
                    if (w == -1) break;
                    y += 2;
                }
                else {
                    out.push_back({x + 1, y});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x - 1, y});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x, y + 1});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x, y + 2});
                    w--;
                    if (w == -1) break;
                    y += 2;
                }
                cur++;
            }
            if (w == -1) cout << "NO" << '\n';
            else {
                cout << "YES" << '\n';
                x = inf / 2, y = inf / 2;
                x -= 2;
                for (auto key : out) cout << key.first << " " << key.second << '\n';
                for (int z = 0; z < b + w; ++z) {
                    cout << x << " " << y << '\n';
                    x--;
                }
            }
        }
        else {
            vector < pair < int, int > > out;
            out.push_back({inf / 2 + 1, inf / 2});
            swap(b, w);
            w--;
            int x = inf / 2 + 1, y = inf / 2;
            int cur = 1;
            bool f = false;
            while (1) {
                if (cur == 1) {
                    out.push_back({x - 1, y});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x + 1, y});;
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x, y - 1});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x, y + 1});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x, y + 2});
                    w--;
                    if (w == -1) break;
                    y += 2;
                }
                else {
                    out.push_back({x + 1, y});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x - 1, y});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x, y + 1});
                    b--;
                    if (b == w) {
                        break;
                    }
                    out.push_back({x, y + 2});
                    w--;
                    if (w == -1) break;
                    y += 2;
                }
                cur++;
            }
            if (w == -1) cout << "NO" << '\n';
            else {
                cout << "YES" << '\n';
                x = inf / 2, y = inf / 2;
                x -= 1;
                for (auto key : out) cout << key.first << " " << key.second << '\n';
                for (int z = 0; z < b + w; ++z) {
                    cout << x << " " << y << '\n';
                    x--;
                }
            }
        }
    }
    return 0;
}