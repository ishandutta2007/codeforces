#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
 
 
int main () {
	int n;
	lli k;
	cin >> n >> k;
	lli x[n];
	fop (i,0,n) {
		cin >> x[i];
	}
	sort(x,x+n);
	lli a,b,minn=x[0],maxx=x[n-1];
	a=upper_bound(x,x+n,minn)-x;
	b=lower_bound(x,x+n,maxx)-x;
	b=n-b;
	while (k>=a or k>=b) {
		if (minn==maxx) break;
		if (a<b) {
			lli tmp=min(k,a*(x[a]-x[a-1]));
			k-=tmp;
			minn+=tmp/a;
			a=upper_bound(x,x+n,minn)-x;
		} else {
			lli tmp=min(k,b*(x[n-b]-x[n-b-1]));
			k-=tmp;
			maxx-=tmp/b;
			b=lower_bound(x,x+n,maxx)-x;
			b=n-b;
		}
	}
	cout << maxx-minn << endl;
}