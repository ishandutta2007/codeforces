#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e6 + 1;
const ll M = 1e3;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

int main() {
    int n, mn1, mx1, mn2, mx2, mn3, mx3;
    cin >> n >> mn1 >> mx1 >> mn2 >> mx2 >> mn3 >> mx3;
    int a1 = mn1, a2 = mn2, a3 = mn3;
    int lft = n - a1 - a2 - a3;
    a1 += min(lft, mx1 - mn1);
    lft -= min(lft, mx1 - mn1);
    a2 += min(lft, mx2 - mn2);
    lft -= min(lft, mx2 - mn2);
    a3 += min(lft, mx3 - mn3);
    cout << a1 << " " << a2 << " " << a3;
}