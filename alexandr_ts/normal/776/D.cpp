#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int M = 1e3 + 2;
const ll INF = 2e9 + 7;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll MAX = 1e15;
const ld EPS = 1e-10;

vector <int> g[N];
vector <int> gc[N];
int a[N];
vector <int> rooms[N];
int used[N];

bool er = false;

void dfs(int v, int c) {
    used[v] = c;
    //cout << v << " " << c << endl;
    fr(i, g[v].size()) {
        if (!used[g[v][i]]) {
            if (gc[v][i] == 1)
                dfs(g[v][i], !(c - 1) + 1);
            else
                dfs(g[v][i], c);
        }
        else {
            //cout << v << " " << g[v][i] << " " << gc[v][i] << endl;
            if (gc[v][i] == 1 && used[g[v][i]] == c ||
                gc[v][i] == 0 && used[g[v][i]] != c)
                er = true;
        }
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, n) {
        cin >> a[i];
        a[i] = !a[i];
    }
    fr(i, m) {
        int cnt;
        cin >> cnt;
        fr(j, cnt) {
            int x;
            cin >> x;
            rooms[x - 1].pb(i);
        }
    }

    fr(i, n) {
        g[rooms[i][0]].pb(rooms[i][1]);
        gc[rooms[i][0]].pb(a[i]);
        g[rooms[i][1]].pb(rooms[i][0]);
        gc[rooms[i][1]].pb(a[i]);
    }

//    fr(i, m) {
//        for (auto t: g[i])
//            cout << t << " ";
//    cout << endl;}
//
    fr(i, m)
        if (!used[i])
            dfs(i, 1);
//
    if (er)
        cout << "NO";
    else
        cout << "YES";
}