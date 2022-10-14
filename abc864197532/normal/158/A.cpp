#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;


int main () {
	int n,k;
	cin >> n >> k;
	k--;
	int a[n];
	fop (i,0,n) cin >> a[i];
	while (a[k]==a[k+1]) {
		k++;
	}
	if (a[k]!=0) cout << k+1 << endl;
	else {
		while (a[k]==0 and k>=0) k--;
		cout << k+1 << endl;
	}
}