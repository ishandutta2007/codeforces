#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

vector <int> g[N];
int col[N];
bool ans;

void dfs(int v, int c) {
    col[v] = c;
    fr(i, g[v].size()) {
        if (col[g[v][i]] == c)
            ans = false;
        if (!col[g[v][i]])
            dfs(g[v][i], c % 2 + 1);
    }
}

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    ld d, h, v, e;
    cin >> d >> h >> v >> e;
    ld v2 = PI * d * d / 4. * e;
    if (v2 > v) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    cout << fixed << setprecision(12) << (PI * d * d / 4) * h / (v - v2);
}