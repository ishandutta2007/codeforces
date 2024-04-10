#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n,h,m;
	cin >> n >> h >> m;
	int aa[n];
	fop (i,0,n) aa[i]=h;
	fop (i,0,m) {
		int l,r,x;
		cin >> l >> r >> x;
		fop (j,l-1,r) {
			aa[j]=min(aa[j],x);
		}
	}
	int sum=0;
	fop (i,0,n) {
		sum+=aa[i]*aa[i];
	}
	cout << sum << endl;
}