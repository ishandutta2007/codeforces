#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 1003;
const int N = 1e6 + 2;



int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector <int> v;

    fr(i, k - 1) {
        if (n == 1) {
            cout << -1;
            return 0;
        }
        bool fnd = false;
        for (int i = 2; i * i <= n && !fnd; i++)
            if (n % i == 0) {
                v.pb(i);
                n /= i;
                fnd = true;
            }
        if (!fnd) {
            v.pb(n);
            n = 1;
        }
    }
    if (n == 1)
        cout << -1;
    else {

    for (auto t: v)
        cout << t << " ";
        cout << n;
    }

}