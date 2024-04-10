#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int t;
	cin >> t;
	while (t--) {
		lli n,m;
		cin >> n >> m;
		lli nums[11];
		lli sum=0;
		fop (i,1,11) {
			nums[i]=m*i%10;
			sum+=nums[i];
		}
		sum*=n/m/10;
		fop (i,1,n/m%10+1) {
			sum+=nums[i];
		}
		cout << sum << endl;
	}
}