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

void solve () {
    int n;
    cin >> n;
    vector <lli> input(n);
    fop (i,0,n) cin >> input[i];
    lli ans = 0, now = input[0];
    int is = (input[0] < 0 ? 0 : 1);
    fop (i,1,n) {
        if (is) {
            if (input[i] > 0) now = max(now, input[i]);
            else {
                ans += now;
                is ^= 1;
                now = input[i];
            }
        } else {
            if (input[i] < 0) now = max(now, input[i]);
            else {
                ans += now;
                is ^= 1;
                now = input[i];
            }
        }
    }
    cout << ans + now << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) solve();
}