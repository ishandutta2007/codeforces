#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n,m;
	cin >> n >> m;
	int nums[m][5],s[m];
	char c;
	fop (i,0,m) {
		fop (j,0,5) {
			nums[i][j]=0;
		}
	}
	fop (i,0,n) {
		fop (j,0,m) {
			cin >> c;
			nums[j][c-'A']++;
		}
	}
	fop (i,0,m) cin >> s[i];
	int sum=0;
	fop (i,0,m) {
		sum+=max(max(max(nums[i][0],nums[i][1]),max(nums[i][2],nums[i][3])),nums[i][4])*s[i];
	}
	cout << sum << endl;
}