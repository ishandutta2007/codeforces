#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

vector<int> G[105];
int arr[105], in[105], ans[105], n;

int query() {
    cout << "?";
    for (int i = 1; i <= n; ++i)
        cout << " " << arr[i];
    cout << endl;
    int rt;
    cin >> rt;
    return rt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        fill(arr + 1, arr + n + 1, 2);
        arr[i] = 1;
        int idx = query();
        if (idx != 0 && idx < i)
            G[idx].pb(i), ++in[i];
    }
    for (int i = 2; i <= n; ++i) {
        fill(arr + 1, arr + n + 1, 1);
        arr[i] = 2;
        int idx = query();
        if (idx != 0 && idx < i)
            G[i].pb(idx), ++in[idx];
    }
    queue<int> q;
    int nw = 0;
    for (int i = 1; i <= n; ++i)
        if (!in[i])
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans[u] = ++nw;
        for (int i : G[u])
            if (!--in[i])
                q.push(i);
    }
    cout << "!";
    for (int i = 1; i <= n; ++i)
        cout << " " << ans[i];
    cout << endl;
}