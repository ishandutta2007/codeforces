#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5 + 1;
const ll M = 2 * 1e3 + 1;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

int a[N], b[N];

bool can(int s, int m) {
    return s >= 0 && s <= 9 * m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int m, s;
    cin >> m >> s;
    if (!can(s, m) || !s && m > 1) {
        cout << "-1 -1";
        return 0;
    }
    if (s == 0 && m == 1) {
        cout << "0 0";
        return 0;
    }

    int sum = s;
    string mx;
    fr(i, m)
        for (int j = 9; j >= 0; j--)
            if ((i || j) && can(sum - j, m - i - 1)) {
                sum -= j;
                mx += ('0' + j);
                break;
            }

    sum = s;
    string mn;
    fr(i, m)
        for (int j = 0; j <= 9; j++)
            if ((i || j) && can(sum - j, m - i - 1)) {
                sum -= j;
                mn += ('0' + j);
                break;
            }
    cout << mn << " " << mx;
 }