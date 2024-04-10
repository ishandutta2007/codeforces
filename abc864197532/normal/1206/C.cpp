#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n;
	cin >> n;
	if (n%2==0) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		int back=1;
		fop (i,1,2*n) {
			cout << back << ' ';
			if (i%2==1) back+=3;
			else back++;
			if (back>2*n) back-=2*n;
		}
		cout << back << endl;
	}
}