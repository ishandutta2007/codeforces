#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 10000*10000;
const ll INF = 2e9 + 10;

int d[102][102][12][12];

void add(int &a, int b) {
    a += b;
    if (a > MOD)
        a -= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    d[0][0][0][0] = 1;
    fr(i1, n1 + 1)
        fr(j1, n2 + 1)
            fr(i2, k1 + 1)
                fr(j2, k2 + 1)
                    if (d[i1][j1][i2][j2]) {
                        add(d[i1 + 1][j1][i2 + 1][0], d[i1][j1][i2][j2]);
                        add(d[i1][j1 + 1][0][j2 + 1], d[i1][j1][i2][j2]);
                    }
    int ans = 0;
    fr(i2, k1 + 1)
        fr(j2, k2 + 1)
            add(ans, d[n1][n2][i2][j2]);
    cout << ans;
}