#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n;
	string s;
	cin >> n >> s;
	int a[n];
	a[0]=s[0]-'0';
	if (a[0]==0) a[0]=-1;
	fop (i,1,n) {
		if (s[i]=='1') {
			a[i]=a[i-1]+1;
		} else {
			a[i]=a[i-1]-1;
		}
	}
	if (a[n-1]!=0) {
		cout << 1 << endl << s << endl;
		return 0;
	}
	fop (i,0,n-1) {
		if (a[i]!=a[n-1] and a[i]!=0) {
			cout << 2 << endl;
			fop (j,0,i+1) cout << s[j];
			cout << ' ';
			fop (j,i+1,n) cout << s[j];
			cout << endl;
			return 0;
		}
	}
}