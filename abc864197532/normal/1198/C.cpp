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


void solve() {
    int n, m, u, v;
    cin >> n >> m;
    vector <int> ans;
    set <int> ind;
    fop (i,0,m) {
        cin >> u >> v;
        u--; v--;
        if (!ind.count(u) and !ind.count(v)) {
            ind.insert(u), ind.insert(v);
            ans.pb(i);
        }
    }
    
    if (ans.size() >= n) {
        cout << "Matching\n";
        fop (i,0,n) cout << ans[i] + 1 << " \n"[i == n - 1];
    } else {
        cout << "IndSet\n";
        int c = 0;
        fop (i,0,3*n) if (!ind.count(i) and c < n) cout << i + 1 << " \n"[c == n - 1], c++;
    }
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}