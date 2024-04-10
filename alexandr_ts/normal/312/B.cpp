#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

ll a[N];

multiset <int> mn, mx;

ld f(ld a, ld b, ld c, ld d) {

}

int main() {
    //freopen("input.txt", "r", stdin);
    ld a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(12);
    cout << a / (b - (b - a) * (d - c) / d);
}