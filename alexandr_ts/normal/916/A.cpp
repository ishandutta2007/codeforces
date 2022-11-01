#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

int main() {
    //freopen("a.in", "r", stdin);
    int x, h, m;
    cin >> x >> h >> m;
    for (int y = 0; y < INF; y++) {
        int tm = ((h * 60 + m - x * y) % (24 * 60) + 24 * 60) % (24 * 60);
        int h1 = tm;
        int m1 = h1 % 60;
        h1 /= 60;
        if (m1 % 10 == 7 || m1 / 10 == 7 || h1 % 10 == 7 || h1 / 10 == 7) {
            cout << y;
            return 0;
        }
    }
}