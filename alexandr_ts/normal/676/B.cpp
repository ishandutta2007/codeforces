#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 100;
const int INF = 2e9 + 1;
const ld EPS = 1e-9;

ld a[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;

    fr(i1, t) {
        a[0][0] += 1;
        fr(i, n)
            fr(j, n)
                if (a[i][j] > 1) {
                    a[i + 1][j] += (a[i][j] - 1) / 2.;
                    a[i + 1][j + 1] += (a[i][j] - 1) / 2.;
                    a[i][j] = 1;
                }
    }
    int cnt = 0;
    fr(i, n)
        fr(j, n)
            if (a[i][j] > 1 - EPS)
                cnt++;
    cout << cnt;
}