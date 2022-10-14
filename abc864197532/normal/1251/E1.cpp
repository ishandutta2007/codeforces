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
#define pli pair<lli,int> 
#define X first
#define Y second


void solve() {
    int n, a, b;
    cin >> n;
    vector <int> cost[n + 1], pre(n + 1);
    fop (i,0,n) {
        cin >> a >> b;
        pre[a + 1]++;
        cost[a].pb(b);
    }
    fop (i,1,n+1) pre[i] += pre[i-1];
    priority_queue <int, vector <int>, greater <int>> q;
    int now = 0;
    lli ans = 0;
    FOP (i,n+1,0) {
        for (int j : cost[i]) q.push(j);
        while (now + pre[i] < i) {
            ans += q.top(); q.pop();
            now++;
        }
    }
    cout << ans << endl;
}


int main () {
    int t;
    cin >> t;
    while (t--) solve();
}