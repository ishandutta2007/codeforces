#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int m,n;
	cin >> m >> n;
	int a[m][n],tmp[m][n];
	vector <pair<int,int> > nums;
	bool is=true;
	fop (i,0,m) {
		fop (j,0,n) {
			cin >> a[i][j];
			tmp[i][j]=a[i][j];
		}
	}
	fop (i,0,m-1) {
		fop (j,0,n-1) {
			if (!is) break;
			if (a[i][j]) {
				if (a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {
					nums.eb(i+1,j+1);
					tmp[i][j]=0;
					tmp[i][j+1]=0;
					tmp[i+1][j]=0;
					tmp[i+1][j+1]=0;
				} else if (tmp[i][j]) {
					is=false;
				}
			}
		}
		if (!is) break;
	}
	fop (i,0,m) {
		fop (j,0,n) {
			if (tmp[i][j]) is=false; 
		}
	}
	if (!is) {
		cout << -1 << endl;
		return 0;
	}
	cout << nums.size() << endl;
	int c,b;
	fop (i,0,nums.size()) {
		tie(b,c)=nums[i];
		cout << b << ' ' << c << endl;
	}
}