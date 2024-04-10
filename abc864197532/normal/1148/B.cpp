#include <bits/stdc++.h>
using namespace std;
 
long long int a[200000],b[200000],n,m,t_a,t_b,k;
 
long long int find(int i) {
	if (i>=n) return -1;
	long long int aa=a[i]+t_a;
	int l=lower_bound(b,b+m,aa)-b;
	if (l+k-i>=m) return -1;
	return b[l+k-i];
}
 
 
int main () {
	cin >> n >> m >> t_a >> t_b >> k;
	int i;
	for (i=0;i<n;++i) cin >> a[i];
	for (i=0;i<m;++i) cin >> b[i];
	long long int max=0;
	for (i=0;i<=k;++i) {
		long long int aa=find(i);
		if (aa==-1) {
			cout << -1 << endl;
			return 0;
		}
		if (max<aa) max=aa;
	}
	cout << max+t_b << endl;
	return 0;
}