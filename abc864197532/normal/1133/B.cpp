#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n,k,aa;
	cin >> n >> k;
	int a[100];
	fop (i,0,100) a[i]=0;
	fop (i,0,n) {
		cin >> aa;
		aa%=k;
		a[aa]++;
	}
	int ans=0;
	ans+=a[0]/2;
	fop (i,1,(k+1)/2) {
		ans+=min(a[i],a[k-i]);
	}
	if (k%2==0) ans+=a[k/2]/2;
	cout << ans*2 << endl;
}