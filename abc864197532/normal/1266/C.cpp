#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 

int main () {
	int r,c;
	cin >> r >> c;
	if (r == 1 and c == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (r < c) {
		fop (i,1,r+1) {
			fop (j,r+1,c+r+1) {
				cout << i*j << ' ';
			}
			cout << endl;
		}
		return 0;
	} else {
		fop (i,c+1,c+r+1) {
			fop (j,1,c+1) {
				cout << i*j << ' ';
			}
			cout << endl;
		}
		return 0;
	}
}