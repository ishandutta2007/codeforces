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


bool used[N];
vector <int> g[N];

void dfs(int v) {
    used[v] = true;
    for (auto it: g[v])
        if (!used[it])
            dfs(it);
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n) {
        int x;
        cin >> x;
        g[i].pb(--x);
        g[x].pb(i);
    }
    int cnt = 0;
    fr(i, n)
        if (!used[i])
            dfs(i), cnt++;
    cout << cnt;
}