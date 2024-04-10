#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n;
	cin >> n;
	int a[n];
	fop (i,0,n) {
		cin >> a[i];
	}
	int m=0,tmp=1;
	fop (i,0,n) {
		if (i<n/2) {
			a[i]-=i;
		} else if (i>=n/2) {
			a[i]-=(n-1-i);
		}
	}
	sort(a,a+n);
	fop (i,1,n) {
		if (a[i]==a[i-1]) {
			tmp++;
		} else {
			if (a[i-1]!=0) m=max(m,tmp);
			tmp=1;
		}
	}
	m=max(m,tmp);
	cout << n-m << endl;
}