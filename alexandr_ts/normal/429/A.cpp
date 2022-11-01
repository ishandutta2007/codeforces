#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 2e5;
const int INF = 2e9;

bool used[N];
int dist[N];

vector <int> g[N];
int a[N], goal[N], ch[N];
int ans;

void rec(int v, int add, int lvl) {
    used[v] = true;
    a[v] ^= (int)(bool)(add & (1 << lvl));
    if (a[v] ^ goal[v])
        ch[v] = 1;
    int new_add = add;
    if (ch[v])
        new_add ^= (1 << lvl);
    fr(i, (int)g[v].size())
        if (!used[g[v][i]])
            rec(g[v][i], new_add, (lvl + 1) % 2);
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n - 1) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }
    fr(i, n)
        cin >> a[i];
    fr(i, n)
        cin >> goal[i];
    rec(0, 0, 0);
    cout << accumulate(ch, ch + n, 0) << endl;
    fr(i, n)
        if (ch[i])
            cout << i + 1 << " ";
}