#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 200200
#define A 30

int m = 1;
int t[M][A], d[M], n, k;

void read() {
    cin >> n >> k;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int r = 1;
        for (int j = 0; j < (int) s.length(); ++j) {
            int x = s[j] - 'a';
            if (t[r][x] == 0) {
                t[r][x] = ++m;
                d[r]++;
            }
            r = t[r][x];
        }
    }
}

bool win(int x, bool fin) {
    if (d[x] == 0)
        return fin;
    for (int k = 0; k < A; ++k)
        if (t[x][k] > 0 && !win(t[x][k], fin))
            return true;
    return false;
}

void kill() {
    bool good, bad;
    good = win(1, false);
    bad = win(1, true);
    if (!good) {
        cout << "Second\n";
        return;
    }
    if (bad) {
        cout << "First\n";
    }
    else {
        if (k % 2 == 1)
            cout << "First\n";
        else
            cout << "Second\n";
    }

}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    kill();


    return 0;
}