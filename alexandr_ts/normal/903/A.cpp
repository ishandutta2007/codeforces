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
const int N = 1e6 + 10;

int main() {
    //freopen("a.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
    int n;
    cin >> n;
    if (n == 1 || n == 2 || n == 4 || n == 5 || n == 8 || n == 11)
        cout << "NO\n";
    else
        cout << "YES\n";
    }
}