#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int a1,a2,k1,k2,n,ans=0;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	int k=n;
	k-=a1*(k1-1);
	k-=a2*(k2-1);
	while (n>0) {
		if (k1>k2) {
			if (a2>0) {
				a2--;
				n-=k2;
				ans++;
			} else {
				a1--;
				n-=k1;
				ans++;
			}
		} else {
			if (a1>0) {
				a1--;
				n-=k1;
				ans++;
			} else {
				a2--;
				n-=k2;
				ans++;
			}
		}
	}
	if (n<0) ans--;
	cout << max(k,0) << ' ' << ans << endl;
}