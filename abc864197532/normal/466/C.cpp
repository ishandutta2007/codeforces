#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n;
	cin >> n;
	lli sum[n+1],summ=0,tmp;
	fop (i,0,n) {
		cin >> tmp;
		sum[i]=summ;
		summ+=tmp;
	}
	sum[n]=summ;
	if (sum[n]%3!=0) {
		cout << 0 << endl;
		return 0;
	}
	lli need=sum[n]/3,k=0;
	summ=0;
	fop (i,1,n+1) {
		if (need==sum[i]-sum[0]) {
			k++;
		} else if (sum[i]-sum[0]==need*2) {
			summ+=k;
		}
	}
	if (need!=0) cout << summ << endl;
	else cout << (k-2)*(k-1)/2 << endl;
}