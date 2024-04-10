#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;
const ll P1 = 17;
const ll P2 = 19;
const ld PI = acos(-1);
const ll MAX = 63211236 + 10;
const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 5e3 + 2;
const int N = 1e6 + 10;

int d[2][M];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "!" << endl << 1 << " " << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "? " << 0 << " " << i << endl;
        int ans;
        cin >> ans;
        d[0][i] = ans;
    }

    for (int i = 1; i < n; i++) {
        cout << "? " << i << " " << 0 << endl;
        int ans;
        cin >> ans;
        d[1][i] = ans;
    }

//    frab(i, 1, n)
//        frab(j, 1, n)
//            d[i][j] = d[i][0] ^ d[0][j];

    vector <int> ansp;
    vector <int> p(n), b(n);
    int cntans = 0;

    for (int i = 0; i < n; i++) {
        p[0] = i;
        frab(j, 1, n)
            p[j] = p[0] ^ d[0][0] ^ d[1][j];
        frab(j, 0, n)
            b[j] = p[0] ^ d[0][j];

        bool ok = true;
        fr(j, n)
            if (p[b[j]] != j)
                ok = false;
        if (ok) {
            ansp = p;
            cntans++;
        }
    }

    cout << "!" << endl << cntans << endl;
    for (auto t: ansp)
        cout << t << " ";
}