#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)

int main () {
	int n;
	cin >> n;
	int a[n],sum=0,b[n],len=0;
	fop(i,0,n) {
		cin >> a[i];
		sum+=a[i];
	}
	sum=sum/2+1;
	sum-=a[0];
	fop(i,1,n) {
		if (a[i]*2<=a[0]) {
			sum-=a[i];
			b[len]=i;
			len++;
			if (sum<=0) break;
		}
	}
	if (sum<=0) {
		cout << len+1 << endl;
		cout << 1 << ' ';
		fop(i,0,len) {
			cout << b[i]+1 << ' ';
		}
		cout << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}