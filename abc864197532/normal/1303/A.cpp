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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0;
        bool is = false;
        fop (i,0,s.length()) {
            if (s[i] == '1') {
                is = true;
            }
            if (s[i] == '0' and is) ans++;
        }
        FOP (i,s.length(), 0) {
            if (s[i] == '0') {
                ans--;
            } else {
                break;
            }
        }
        cout << max(ans, 0) << endl;
    }
}