#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ll INF = 2e9;
const ld EPS = 1e-8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int curx = 0, cury = 0;
    int way = 1;
    fr(i, k - 1) {
        cout << 2 << " " << curx + 1 << " " << cury + 1 << " ";
        cury += way;
        if (way == 1 && cury == m) {
            way = -1;
            curx++;
            cury--;
        }
        if (way == -1 && cury == -1) {
            way = 1;
            cury = 0;
            curx++;
        }
        cout << curx + 1 << " " << cury + 1 << endl;
        cury += way;
        if (way == 1 && cury == m) {
            way = -1;
            curx++;
            cury--;
        }
        if (way == -1 && cury == -1) {
            way = 1;
            cury = 0;
            curx++;
        }
    }
    cout << n * m - 2 * k + 2 << " ";
    fr(i, n * m - 2 * k + 2) {
        cout << curx + 1 << " " << cury + 1 << " ";
        cury += way;
        if (way == 1 && cury == m) {
            way = -1;
            curx++;
            cury--;
        }
        if (way == -1 && cury == -1) {
            way = 1;
            cury = 0;
            curx++;
        }
    }
}