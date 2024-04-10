#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n,x,a,b,maxx=0,max2=0;
		cin >> n >> x;
		fop (i,0,n) {
			cin >> a >> b;
			maxx=max(maxx,a);
			max2=max(max2,a-b);
		}
		if (x<=maxx) cout << 1 << endl;
		else if (max2<=0) cout << -1 << endl;
		else cout << (x-maxx-1)/max2+2 << endl;
	}
}