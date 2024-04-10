#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 301;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

int d[N][3];
int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i + 1];
    frab(i, 1, n + 1) {
        d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
        if (a[i] == 1 || a[i] == 3)
            d[i][1] = max(d[i - 1][0], d[i - 1][2]) + 1;
        if (a[i] == 2 || a[i] == 3)
            d[i][2] = max(d[i - 1][0], d[i - 1][1]) + 1;
    }
    cout << n - max(max(d[n][0], d[n][1]), d[n][2]);
}