#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 7;
const int M = 1e3 + 5;
const int N = 1e6 + 5;
const int POW = 20;
const ll MOD = 1000 * 1000 * 1000 + 7;


int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int x1, y1, x2, y2, a, b;
    cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
    if (!((x1 - x2) % a == 0 && (y1 - y2) % b == 0)) {
        cout << "NO";
        return 0;
    }
    int t1 = abs(x1 - x2) / a;
    int t2 = abs(y1 - y2) / b;
    if (t1 % 2 != t2 % 2)
        cout << "NO";
    else
        cout << "YES";
}