#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
int n,k;
lli MOD=1e9+7;
lli a[100001],sum[100001];


int main () {
	cin >> n >> k;
	fop (i,1,k) {
		a[i]=1;
	}
	a[k]=2;
	fop (i,k+1,100001) {
		a[i]=a[i-1]+a[i-k];
		a[i]%=MOD;
	}
	lli summ=0;
	sum[0]=0;
	fop (i,1,100001) {
		summ+=a[i];
		sum[i]=summ;
		summ%=MOD;
		sum[i]%=MOD;
	}
	int b,c;
	fop (i,0,n) {
		cin >> b >> c;
		if (sum[c]>=sum[b-1]) cout << sum[c]-sum[b-1] << endl;
		else cout << MOD+sum[c]-sum[b-1] << endl;
	}
}