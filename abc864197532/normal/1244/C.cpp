#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	lli n,m,a,b;
	cin >> n >> m >> a >> b;
	lli k=0,y=0;
	bool is=false;
	fop (i,0,a) {
		if (k>=a) {
			k%=a;
		}
		if (k==m%a) {
			y=i;
			is=true; 
			break;
		}
		k+=b;
	}
	lli x=(m-y*b)/a;
	if (y+x>n or x<0 or !is) {
		cout << -1 << endl;
	} else {
		cout << x << ' ' << y << ' ' << n-x-y << endl;
	}
}