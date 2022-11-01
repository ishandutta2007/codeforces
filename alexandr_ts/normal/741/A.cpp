#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 1;
const int M = 101;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-13;

bool used[N];
vector <int> g[N];

int dfs(int v, int cnt) {
    used[v] = cnt;
    if (!used[g[v][0]])
        return dfs(g[v][0], cnt + 1);
    else
        return cnt;
}

int main() {
    int n;
    cin >> n;
    int v;
    vector <int> dif;
    for (int i = 0; i< n; i++) {
        cin >> v;
        v--;
        dif.pb(v);
        g[i].pb(v);
    }
    sort(dif.begin(), dif.end());
    for (int i = 0; i < n; i++)
    if (dif[i] != i) {
        cout << -1;
        return 0;
    }

    int ans = 1;
    vector <int> len;
    bool odd = false;
    for (int i = 0; i < n; i++)
        if (!used[i]) {
            int t = dfs(i, 1);
            if (t % 2)
                odd = true;
            len.pb(t);
        }
    sort(len.begin(), len.end());
    for (int i = 0; i< len.size(); i++)
        if (len[i] % 2)
            ans = ans * len[i] / __gcd(ans, len[i]);
        else
            ans = ans * (len[i]/ 2) / __gcd(ans, len[i] / 2);
    cout << ans << endl;
    return 0;
}