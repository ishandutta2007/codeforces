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

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];

    if (n == 1 && a[0] == 0) {
        cout << "UP";
        return 0;
    }
    if (n == 1 && a[0] == 15) {
        cout << "DOWN";
        return 0;
    }

    if (n <= 1) {
        cout << -1;
        return 0;
    }

    int mx = 15;
    int mn = 0;
    if (a[n - 1] == mn)
        cout << "UP";
    else if (a[n - 1] == mx)
        cout << "DOWN";
    else if (a[n - 1] < a[n - 2])
        cout << "DOWN";
    else
        cout << "UP";
}