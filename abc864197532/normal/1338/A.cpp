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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        lli input[n];
        fop (i,0,n) cin >> input[i];
        lli need[n], now = input[0], all = 0;
        fop (i,1,n) {
        	need[i] = max(0ll, now - input[i]);
			now = max(now, input[i]);
			all = max(need[i], all);
		}
		int ans = 0;
		while (all > 0) {
			ans++;
			all /= 2;
		}
		cout << ans << endl;
    }
}