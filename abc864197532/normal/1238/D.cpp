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
    int n;
    string s;
    cin >> n >> s;
    lli ans = 1ll * n * (n - 1) / 2;
    vector <int> aa;
    int now = 1;
    fop (i,1,n) {
        if (s[i] == s[i-1]) {
            now++;
        } else {
            aa.pb(now);
            now = 1;
        }
    }
    aa.pb(now);
    lli tmp = 2 * n;
    tmp -= aa[0];
    tmp -= aa.back();
    tmp -= (aa.size() - 1);
    cout << ans - tmp << endl;
}