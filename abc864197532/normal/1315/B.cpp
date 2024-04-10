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
    int a[2], p, c = 0;
    string s;
    int ans = 1;
    cin >> a[0] >> a[1] >> p >> s;
    s.back() = 'C';
    FOP (i,s.length()-1,0) {
        if (s[i] != s[i+1]) {
            p -= a[s[i] - 'A'];
            if (p < 0) {
                ans = i + 2;
                break;
            }
        }
    }
    cout << ans << endl;
}


int main () {
    int t;
    cin >> t;
    while (t--) solve();
}