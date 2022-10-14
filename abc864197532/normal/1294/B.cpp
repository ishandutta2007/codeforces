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
	    int n;
	    cin >> n;
	    string s = "";
	    pii point[n+1];
	    fop (i,0,n) cin >> point[i].first >> point[i].second;
	    point[n] = mp(0,0);
	    bool is = true;
	    sort(point, point + n + 1);
	    fop (i,1,n+1) {
	        if (point[i].second < point[i-1].second) {
	            is = false;
	            break;
	        } else {
	            fop (j,point[i-1].first, point[i].first) s += 'R';
	            fop (j,point[i-1].second, point[i].second) s += 'U';
	        }
	    }
	    if (is) {
	        cout << "YES" << endl << s << endl;
	    } else {
	        cout << "NO" << endl;
	    }
	}
}