#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 10;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;




int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if (n <= 3) {
        cout << -1;
        return 0;
    }
    if (n == 4) {
        if (k == 3)
            cout << "3\n1 2\n2 3\n3 4";
        else
            cout << -1;
        return 0;
    }
    if (k == 2) {
        cout << n - 1 << endl;
        frab(i, 1, n)
        cout << i << " " << i + 1 << endl;
        return 0;
    }
    if (k == 3) {
        cout << 2 * n - 5 << endl;
        cout << "1 2\n2 3\n3 4\n";
        frab(i, 5, n + 1)
            cout << "2 " << i << endl << i << " 3" << endl;
        return 0;
    }
    cout << -1;

}