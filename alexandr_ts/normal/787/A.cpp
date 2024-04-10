#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int t = max(0, (d - b + a - 1) / a); t < 100000; t++)
        if ((b + t * a - d) % c == 0) {
            cout << a * t + b;
            return 0;
        }
    cout << -1;
}