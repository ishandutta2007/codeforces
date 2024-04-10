#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e2 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 5e6 + 1;
const int MAX2 = 1e4;

vector <int> g[N][N];
bool used[N];

void dfs(int v, int col) {
    used[v] = true;
    fr(i, (int)g[col][v].size())
        if (!used[g[col][v][i]])
            dfs(g[col][v][i], col);
}

int main() {
    //freopen("input.txt", "r", stdin);
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;
    fr(i1, t)
        fr(i2, t)
            if (x == a - da * i1 + b - db * i2 || x == a - da * i1 || x == 0 || x == b - db * i2) {
                cout << "YES";
                return 0;
            }
    cout << "NO";


}