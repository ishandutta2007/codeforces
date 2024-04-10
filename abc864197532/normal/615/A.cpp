#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)


int main () {
	int n,m,a,t;
	string s;
	cin >> n >> m;
	int nums[m];
	fop(i,0,m) nums[i]=0;
	fop(i,0,n) {
		cin >> a;
		fop (i,0,a) {
			cin >> t;
			nums[t-1]=1;
		}
	}
	fop(i,0,m) {
		if (nums[i]==0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}