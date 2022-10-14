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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int aa = (k + 1) >> 1;
    int count[aa][26];
    fop (i,0,aa) fop (j,0,26) count[i][j] = 0;
    fop (i,0,n) {
        int tmp = i % k;
        if (tmp < aa) count[tmp][s[i] - 'a']++;
        else count[k - 1 - tmp][s[i] - 'a']++;
    }
    int ans = 0;
    fop (i,0,aa) {
        int tmp = 0;
        fop (j,0,26) {
            tmp = max(tmp, count[i][j]);
        }
        ans += tmp;
    }
    cout << n - ans << endl;
}




int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}