#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 3;
const ll MOD = 10000*100000 + 7;
const ll INF = 2e15 + 10;
const ll MAX = 10000000;

int a[N];
vector <int> g[N], g2[N];
int tout[N], tin[N];
int t = 1;
bool er = false;
void dfs(int v) {
    tin[v] = t++;
    for (auto t1: g[v]) {
        if (tin[t1] && !tout[t1])
            er = true;
        else if (!tin[t1] && !tout[t1])
            dfs(t1);
    }
    tout[v] = t++;
}

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    fr(i, k) {
        cin >> a[i];
        a[i]--;
    }
    fr(i, n) {
        int t;
        cin >> t;
        fr(j, t) {
            int x;
            cin >> x;
            g[i].pb(--x);
        }
    }

    fr(i, k)
        if (!tin[a[i]])
            dfs(a[i]);
    if (er) {
        cout << -1;
        return 0;
    }

    vector <pair <int, int> > b;
    fr(i, n)
        if (tin[i])
            b.pb(mp(tout[i], i));
    sort(b.begin(), b.end());
    cout << b.size() << endl;
    for (auto t: b)
        cout << t.second + 1 << " ";

}