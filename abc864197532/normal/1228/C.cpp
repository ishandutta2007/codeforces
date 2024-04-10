#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
lli MOD=1e9+7;

lli pow(int a,lli n) {
	if (n==0) return 1;
	if (n==1) return a;
	lli aa=pow(a,n/2);
	aa*=aa;
	aa%=MOD;
	aa*=pow(a,n%2);
	return aa%MOD;
}

int main () {
	int x;
	lli n;
	cin >> x >> n;
	int k=x;
	set <int> nums;
	for (int i=2; i*i<=x and k>1; ++i) {
		if (k%i==0) nums.insert(i);
		while (k%i==0) {
			k/=i;
		}
	}
	if (k>1) nums.insert(k);
	lli ans=1;
	for (auto i: nums) {
		lli k=0,p=i;
		while (true) {
			lli aa=n/p;
			k+=aa;
			if (aa<i) break;
			p*=i;
		}
		ans*=pow(i,k);
		ans%=MOD;
	}
	cout << ans << endl;
}