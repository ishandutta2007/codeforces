#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3 + 10;
const ll INF = 2e5 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        fr(j, m)
            cin >> a[i][j];
    int ans = 0;
    fr(i, n) {
        bool fnd = false;
        fr(j, m)
            if (!a[i][j] && fnd)
                ans++;
            else if (a[i][j])
                fnd = true;
    }
    fr(i, n) {
        bool fnd = false;
        for (int j = m - 1; j >= 0; j--)
            if (!a[i][j] && fnd)
                ans++;
            else if (a[i][j])
                fnd = true;
    }
    fr(j, m) {
        bool fnd = false;
        fr(i, n)
            if (!a[i][j] && fnd)
                ans++;
            else if (a[i][j])
                fnd = true;
    }
    fr(j, m) {
        bool fnd = false;
        for (int i = n - 1; i >= 0; i--)
            if (!a[i][j] && fnd)
                ans++;
            else if (a[i][j])
                fnd = true;
    }
    cout << ans;
}