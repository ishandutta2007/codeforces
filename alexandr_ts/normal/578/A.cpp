#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair <int, int> pr;

const ll N = 1e6 + 1;
const ll M = 1e3;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        printf("%.10lf", (ld)a);
        return 0;
    }
    if (a < b) {
        cout << -1;
        return 0;
    }
    ll q = (a + b) / 2 / b;
    ll len = (2 * q - 1) * b;
    ld ans = (ld)b + ((ld)a - (ld)len) / (2.0 * (ld)q);
    printf("%.10lf", (ld)ans);
}