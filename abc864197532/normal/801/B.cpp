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
    string s,t, ans="";
    cin >> s >> t;
    int n = s.length();
    fop (i,0,n) {
        if (s[i] < t[i]) {
            cout << -1 << endl;
            return 0;
        } else if (s[i] == t[i]) {
            ans += s[i];
        } else {
            ans += t[i];
        }
    }
    cout << ans << endl;
}