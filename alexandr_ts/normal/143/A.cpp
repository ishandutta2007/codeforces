#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-8;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    if (r1 + r2 != c1 + c2 || r1 + r2 != d1 + d2) {
        cout << -1;
        return 0;
    }
    frab(i1, 1, 10)
        frab(i2, 1, 10)
            frab(i3, 1, 10)
                frab(i4, 1, 10)
                    if (i1 != i2 && i1 != i3 && i1 != i4 && i2 != i3 && i2 != i4 && i3 != i4)
                    if (i1 + i2 == r1 && i3 + i4 == r2 && i1 + i3 == c1 && i2 + i4 == c2 && i1 + i4 == d1 && i2 + i3 == d2) {
                        cout << i1 << " " << i2 << endl << i3 << " " << i4;
                        return 0;
                    }
    cout << -1;

}