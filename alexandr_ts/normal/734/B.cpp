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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int c2 = min(min(a, c), d);
    int c1 = min(b, a - c2);
    cout << c2 * 256 + c1 * 32;
}