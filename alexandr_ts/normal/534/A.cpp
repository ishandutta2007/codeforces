#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e4;
const int INF = 2 * 1e9 + 1;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl << 1;
        return 0;
    }
    if (n == 2) {
        cout << 1 << endl << "1";
        return 0;
    }
    if (n == 3) {
        cout << 2 << endl << "1 3";
        return 0;
    }
    if (n == 4) {
        cout << 4 << endl << "3 1 4 2";
        return 0;
    }
    cout << n << endl;
    for (int i = 0; i < n; i += 2)
        cout << i + 1 << " ";
    for (int i = 1; i < n; i+= 2)
        cout << i + 1 << " ";
}