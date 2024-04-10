#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[100000],x,y,n;

bool find (int k) {
	for (int i=k-x;i<=k+y;++i) {
		if (i<0) continue;
		if (i>=n) break;
		if (a[i]<=a[k] and i!=k) return false;
	}
	return true;
}

int main () {
	cin >> n >> x >> y;
	for (int i=0;i<n;++i) cin >> a[i];
	for (int i=0;i<n;++i) {
		if (find(i)) {
			cout << i+1 << endl;
			return 0;
		}
	}
}