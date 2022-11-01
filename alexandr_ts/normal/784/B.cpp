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

int a[N];

int f(int x) {
    if (x == 0) return 1;
    if (x == 4) return 1;
    if (x == 6) return 1;
    if (x == 8) return 2;
    if (x == 9) return 1;
    if (x == 10) return 1;
    if (x == 11) return 2;
    if (x == 13) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    ll n;
    cin >> n;
    if (n == 0) {
        cout << 1;
        return 0;
    }
    int ans = 0;
    while (n) {
        ans += f(n % 16);
        n /= 16;
    }
    cout << ans;
}