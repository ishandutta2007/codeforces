#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int MX = 10000001;
const int N = 500005;

int minp[MX];
int a[N];
int n;
int d1[N], d2[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i < MX; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            if (i > 4000) continue;
            for (int j = i * i; j < MX; j += i) if (minp[j] == 0) minp[j] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        int u = a[i];
        // cout << u << ' ';
        d1[i] = 1;
        int p = minp[u];
        // cout << p << ' ';
        while (u % p == 0) {
            u /= p;
            d1[i] *= p;
        }
        // cout << d1[i] << endl;
        if (u == 1) d1[i] = d2[i] = -1;
        else d2[i] = u;
    }
    for (int i = 1; i <= n; i++) cout << d1[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << d2[i] << ' ';
    return 0;
}