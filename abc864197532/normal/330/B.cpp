#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    bool count[n];
    fop (i,0,n) count[i] = false;
    fop (i,0,m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        count[u] = count[v] = true;
    }
    int aa = 0;
    fop (i,0,n) if (!count[i]) aa = i;
    cout << n - 1 << '\n';
    fop (i,0,n) {
        if (aa == i) continue;
        cout << i + 1 << ' ' << aa + 1 << '\n';
    }
}