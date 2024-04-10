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

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
	    string t;
	    cin >> t;
	    int now = 1, maxx = 0;
	    char c = t[0];
	    if (c == 'L') maxx = now;
	    fop (i,1,t.length()) {
	        if (c == t[i]) now++;
	        else {
	            if (c == 'L') maxx = max(maxx, now);
	            c = t[i];
	            now = 1;
	        }
	    }
	    if (c == 'L') maxx = max(maxx, now);
	    cout << maxx + 1 << endl;
	}
}