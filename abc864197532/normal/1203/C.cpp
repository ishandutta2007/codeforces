#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;

lli gcd(lli a,lli b) {
	if (a<b) {
		lli tmp=a;
		a=b;
		b=tmp;
	}
	if (a%b==0) return b;
	return gcd(a%b,b);
}


int main () {
 	ios_base::sync_with_stdio(false);
	cin.tie(0);
	lli n,g,tmp;
	cin >> n >> g;
	fop (i,1,n) {
		cin >> tmp;
		g=gcd(g,tmp);
	}
	lli c=0,i;
	for (i=1;i*i<g;++i) {
		if (g%i==0) c++;
	}
	c*=2;
	if (i*i==g) c++;
	cout << c << endl;
}