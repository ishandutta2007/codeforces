#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n,b_max,a_max;
	cin >> n >> b_max >> a_max;
	int s[n];
	fop (i,0,n) cin >> s[i];
	int m=-1,a=a_max,b=b_max;
	fop (i,0,n) {
		if (m!=-1) break;
		if (s[i]) {
			if (b>0 and a<a_max) {
				b--;
				a++;
			} else if (a>0) a--;
			else if (b>0) b--;
			else m=i;
		} else {
			if (a>0) a--;
			else if (b>0) b--;
			else m=i;
		}
	}
	if (m==-1) m=n;
	cout << m << endl;
}