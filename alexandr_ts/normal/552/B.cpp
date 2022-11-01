#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3;
const int INF = 2 * 1e9 + 1;
const int C = 100;
const int C2 = 100000;
const int C3 = 100000000;

ll a[N][N];

int len(int x) {
    int c = 0;
    while (x > 0)
        c++, x /= 10;
    return c;
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    //ld cl = clock();
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i % C == 0 && i + C <= n) {
            ans += (C) * len(i);
            i += (C - 1);
        }
        else if (i % C2 == 0 && i + C2 <= n) {
            ans += (C2) * len(i);
            i += (C2 - 1);
        }
        else if (i % C3 == 0 && i + C3 <= n) {
            ans += (C3) * len(i);
            i += (C3 - 1);
        }
        else
            ans += len(i);

    }
    cout << ans;
    //cout << endl << clock() - cl;

}