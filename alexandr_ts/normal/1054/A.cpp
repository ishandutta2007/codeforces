#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;



int main() {
    //freopen("a.in", "r", stdin);
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int pesh = abs(x - y) * t1;
    int lift = abs(x - z) * t2 + t3 + t3 + abs(x - y) * t2 + t3;
    if (pesh >= lift)
        cout << "YES";
    else
        cout << "NO";
}