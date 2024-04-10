#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n,k=0;
	bool is=true;
	lli sum=0;
	cin >> n;
	int a[n];
	fop (i,0,n) {
		cin >> a[i];
		if (a[i]>0) {
			sum+=a[i]-1;
		}else if (a[i]==0) {
			sum++;
			is=false;
		} else {
			sum+=-1-a[i];
			k++;
		}
	}
	if (k%2!=0 and is) sum+=2;
	cout << sum << endl;
}