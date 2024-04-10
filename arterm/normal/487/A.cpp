#include <bits/stdc++.h>

using namespace std;

#define INF 1000000

struct ncp {
    int hp, atk, def;
    void read() {
        cin >> hp >> atk >> def;
    }
} y, m;

int dominate() {
    int dm = max(0, y.atk - m.def);
    int dy = max(0, m.atk - y.def);
    if (dm == 0)
        return INF;
    int steps = (m.hp + dm - 1) / dm;
    return max(0, steps * dy - y.hp + 1);
}

int main() {
    y.read();
    m.read();
    int a, b, c, ans = INF;
    cin >> a >> b >> c;
    for (int i = 0; i <= 300; ++i)
        for (int j = 0; j <= 300; ++j) {
            y.atk += i;
            y.def += j;
            ans = min(ans, a * dominate() + i * b + j * c);
            y.atk -= i;
            y.def -= j;
        }

    cout << ans << "\n";
    return 0;
}