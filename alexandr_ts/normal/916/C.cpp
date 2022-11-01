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
const int M = 1e6 + 3;
const int N = 1e6 + 10;
const int MX = 1e9;

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    cout << M << " " << M << endl;
    cout << "1 2 " << M - (n - 2) << "\n";
    for (int i = 1; i < n - 1; i++) {
        cout << i + 1 << " " << i + 2 << " 1\n";
    }
    int k = m - (n - 1);
    for (int i = 1; i <= n && k; i++)
        for (int j = i + 2; j <= n && k; j++) {
            cout << i << " " << j << " " << MX << "\n";
            k--;
        }
}