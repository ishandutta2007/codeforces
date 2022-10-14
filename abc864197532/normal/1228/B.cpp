#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	int m,n,tmp;
	cin >> n >> m;
	lli MOD=1e9+7;
	int nums[n][m];
	fop (i,0,n) {
		fop (j,0,m) {
			nums[i][j]=-1;
		}
	}
	fop (i,0,n) {
		cin >> tmp;
		fop (j,0,tmp) nums[i][j]=1;
		if (tmp<m) nums[i][tmp]=0;
	}
	bool is=false;
	fop (i,0,m) {
		cin >> tmp;
		fop (j,0,tmp) {
			if (nums[j][i]==0) is=true;
			nums[j][i]=1;
		}
		if (tmp<n) {
			if (nums[tmp][i]==1) is=true;
			nums[tmp][i]=0;
		}
	}
	if (is) {
		cout << 0 << endl;
		return 0;
	}
	lli ans=1;
	fop (i,0,n) {
		fop (j,0,m) {
			if (nums[i][j]==-1) {
				ans*=2;
				ans%=MOD;
			}
		}
	}
	cout << ans << endl;
}