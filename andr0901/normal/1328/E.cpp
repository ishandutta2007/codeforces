#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <vector <int>> gr;
vector <int> par, height, tin, tout;
int timer = 0;

void dfs(int v, int p = -1, int h = 0) {
    if (p == -1)
        par[v] = 0;
    else
        par[v] = p;
    tin[v] = timer++;
    height[v] = h;
    for (int u : gr[v])
        if (u != p)
            dfs(u, v, h + 1);
    tout[v] = timer++;
}

bool cmp(int a, int b) {
    return height[a] < height[b];
}

bool is_par(int v, int u) {
    return tin[v] < tin[u] && tout[v] > tout[u];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    gr.resize(n);
    forn (i, 1, n) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[v].pb(u), gr[u].pb(v);
    }
    par = height = tin = tout = vector <int> (n);
    dfs(0);
    while (q --> 0) {
        int k;
        cin >> k;
        vector <int> a(k);
        cin >> a;
        forn (i, 0, k) {
            a[i]--;
            a[i] = par[a[i]];
        }
        sort(all(a), cmp);
        //cout << a << "\n";
        bool yes = true;
        forn (i, 0, k - 1)
            if (a[i] != a[i + 1] && !is_par(a[i], a[i + 1])) 
                yes = false;
        if (yes)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}