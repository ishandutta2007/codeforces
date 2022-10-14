#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n,tmp;
	cin >> n;
	int a[4];
	fop (i,0,4) a[i]=0;
	fop (i,0,n) {
		cin >> tmp;
		a[tmp-1]++;
	}
	int all=0,m=min(a[0],a[2]);
	// 1
	all+=a[3];
	a[3]=0;
	// 2
	all+=m;
	a[0]-=m;
	a[2]-=m;
	// 3
	all+=a[2];
	// 4
	all+=(a[0]+a[1]*2+3)/4;
	cout << all << endl;
}