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
    int n, m, tmp;
    string s;
    cin >> n >> m >> s;
    int b[m];
    int a[n+1][26];
    fop (i,0,26) a[0][i] = 0;
    fop (i,0,n) {
        fop (j,0,26) {
            a[i+1][j] = a[i][j] + (s[i] - 'a' == j);
        }
    }
    vector <int> ans(26, 0);
    fop (i,0,m) {
        cin >> tmp;
        fop (j,0,26) ans[j] += a[tmp][j];
    }
    fop (i,0,26) ans[i] += a[n][i];
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}


int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}