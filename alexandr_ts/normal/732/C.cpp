#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 501;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

ll a[N];

int main() {
    //freopen("a.in", "r", stdin);
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] == a[2]) {
        cout << 0;
        return 0;
    }
    if (a[2] == a[1]) {
        cout << a[1] - a[0] - 1;
        return 0;
    }
    cout << a[2] - a[0] - 1 + a[2] - a[1] - 1;
}