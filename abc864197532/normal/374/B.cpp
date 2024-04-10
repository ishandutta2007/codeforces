#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli>
#define X first
#define Y second
const int mod = 998244353;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int now = 0;
    lli ans = 1;
    int n = s.length();
    fop (i,1,n) {
        now++;
        if ((s[i] - '0') + (s[i - 1] - '0') != 9) {
            if (now & 1) ans *= (now / 2 + 1);
            now = 0;
        }
    }
    if (now % 2 == 0) ans *= (now / 2 + 1);
    cout << ans << endl;
    
}