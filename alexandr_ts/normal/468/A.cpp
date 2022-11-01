#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e12 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

ll x[N], h[N], l[N], r[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    if (n < 4) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for (; n > 5; n -= 2) {
        cout << n << " - " << n - 1 << " = " << 1 << endl;
        cout << "1 * 1 = 1" << endl;
    }
    if (n == 4) {
        cout << "1 * 2 = 2" << endl;
        cout << "2 * 3 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
    }
    if (n == 5) {
        cout << "3 * 5 = 15" << endl;
        cout << "2 * 4 = 8" << endl;
        cout << "15 + 8 = 23" << endl;
        cout << "23 + 1 = 24" << endl;
    }
}