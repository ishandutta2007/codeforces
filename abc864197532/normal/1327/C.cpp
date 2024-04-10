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
const int mod = 998244353;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string ans;
    fop (i,0,n-1) ans.pb('D');
    fop (i,0,m-1) ans.pb('R');
    fop (i,0,m) {
        fop (_,0,n-1) ans.pb(i & 1 ? 'D' : 'U');
        ans.pb('L');
    }
    cout << ans.length() << endl << ans << endl;
}