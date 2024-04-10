#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ld EPS = 1e-8;
const int M = 1e2 + 12;
const int MAX = 1e3 + 1;
const int N = 2e6 + 1;

vector <int> g[N];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    frab(i, 0, n - 1)
        g[i % k].pb(i);
    cout << g[0].size() + g[1].size() << endl;
    fr(i, k)
        cout << n << " " << i + 1 << endl;
    fr(i, k)
        fr(j, (int)g[i].size() - 1)
            cout << g[i][j] + 1 << " " << g[i][j + 1] + 1 << endl;


}