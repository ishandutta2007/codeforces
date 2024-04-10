#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

int main() {
    //freopen("a.in", "r", stdin);
    int a, b;
    cin >> a >> b;
    if (abs(a - b) <= 1 && a + b > 0)
        cout << "YES";
    else
        cout << "NO";
}