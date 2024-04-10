#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e4 + 1;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

int x[N], y[N];

int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    fr(i, 3)
        cin >> x[i] >> y[i];
    cout << 3 << endl;
    fr(i, 3)
        cout << x[i] + (x[(i + 2) % 3] - x[(i + 1) % 3]) << " " <<
            y[i] + (y[(i + 2) % 3] - y[(i + 1) % 3]) << endl;
}