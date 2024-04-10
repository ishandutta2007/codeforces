#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ld EPS = 1e-9;

int main() {
    //freopen("a.in", "r", stdin);
    ll a, b, s;
    cin >> a >> b >> s;
    a = abs(a);
    b = abs(b);
    if (a + b <= s && (s - a - b) % 2 == 0)
        cout <<"Yes";
    else
        cout << "No";
}