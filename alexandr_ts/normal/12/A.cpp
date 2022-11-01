#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e2 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 5e6 + 1;
const int MAX2 = 1e4;

char a[N][N];

int main() {
    //freopen("input.txt", "r", stdin);
    fr(i, 3)
        fr(j, 3)
            cin >> a[i][j];
    fr(i, 3)
        fr(j, 3)
            if (a[i][j] != a[2 - i][2 - j]) {
                cout << "NO";
                return 0;
            }
    cout << "YES";
}