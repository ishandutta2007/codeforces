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
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int now = -10000, ans = 0;
        fop (i,0,n) {
            if (s[i] == 'P') now++;
            else {
                ans = max(ans,now);
                now = 0;
            }
        }
        cout << max(ans,now) << endl;
    }
}