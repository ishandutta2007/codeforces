#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const int N = 2e2 + 10;

int a[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        fr(j, n)
            cin >> a[i][j];
    bool ok = true;
    fr(i, n)
        fr(j, n) {
            if (a[i][j] == 1) continue;
            bool fnd = false;
            fr(i1, n)
                fr(j1, n)
                    if (i1 != i && j1 != j)
                        if (a[i][j1] + a[i1][j] == a[i][j])
                            fnd = true;
            if (!fnd) {
                cout << "No";
                return 0;
            }
        }
    cout << "Yes";
}