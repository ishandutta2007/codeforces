#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 300;
const int N = 1e5 + 2;

int a[N];
int l[N], r[N];
bool pr[N];

int tl[N], tr[N];

void dfs(int v, int l1, int r1) {
    tl[v] = l1, tr[v] = r1;
    if (l[v] >= 0)
        dfs(l[v], l1, min(r1, a[v] - 1));
    if (r[v] >= 0)
        dfs(r[v], max(l1, a[v] + 1), r1);
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i] >> l[i] >> r[i];
        l[i]--, r[i]--;
        pr[l[i]] = pr[r[i]] = true;
    }

    int root = -1;
    fr(i, n)
        if (!pr[i])
            root = i;

    dfs(root, -INF, INF);
    set <int> fnd;
//    fr(i, n)
//        cout << tl[i] << ' ' << tr[i] << endl;
    fr(i, n)
        if (tl[i] <= a[i] && a[i] <= tr[i])
            fnd.insert(a[i]);

    int ans = 0;
    fr(i, n)
        if (fnd.count(a[i]))
            ans++;
    cout << n - ans;
}