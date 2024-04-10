#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 1e6;
const ld EPS = 1e-8;
const ld INF = 1e15;

ll a[4][2];

int main() {
    ld st = clock();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    a[3][0] = 1;
    frab(i, 1, 1 + n) {
        a[0][i % 2] = (a[1][(i - 1) % 2] + a[2][(i - 1) % 2] + a[3][(i - 1) % 2]) % MOD;
        a[1][i % 2] = (a[0][(i - 1) % 2] + a[2][(i - 1) % 2] + a[3][(i - 1) % 2]) % MOD;
        a[2][i % 2] = (a[1][(i - 1) % 2] + a[0][(i - 1) % 2] + a[3][(i - 1) % 2]) % MOD;
        a[3][i % 2] = (a[1][(i - 1) % 2] + a[2][(i - 1) % 2] + a[0][(i - 1) % 2]) % MOD;
    }
    cout << a[3][n % 2];
}