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
	    int n, tmp;
	    cin >> n;
	    int a[n+1];
	    fop (i,0,n+1) a[i] = -1;
	    bool is = false;
	    fop (i,0,n) {
	        cin >> tmp;
	        if (a[tmp] == -1) a[tmp] = i;
	        else {
	            if (i - a[tmp] != 1) is = true;
	        }
	    }
	    if (is) cout << "YES" << endl;
	    else cout << "NO" << endl;
	}
}