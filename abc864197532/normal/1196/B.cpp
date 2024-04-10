#include <bits/stdc++.h>
using namespace std;
#define lli long long int


int main () {
	int t;
	cin >> t;
	for (int i=0;i<t;++i) {
		int n,k,now=0;
		cin >> n >> k;
		int a[n];
		lli tmp;
		for (int j=0;j<n;++j) {
			cin >> tmp;
			if (tmp%2==1) {
				a[now]=j;
				now++;
			}
		}
		if (now>=k and now%2==k%2) {
			cout << "YES" << endl;
			for (int j=now-k;j<now-1;++j) {
				cout << a[j]+1 << ' ';
			}
			cout << n; 
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}