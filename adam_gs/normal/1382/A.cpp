#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int a[n], b[m], la=0, lb=0;
		rep(i, n) cin >> a[i];
		rep(i, m) cin >> b[i];
		sort(a, a+n);
		sort(b, b+m);
		int ans=-1;
		while(la<n && lb<m) {
			if(a[la]==b[lb]) {
				ans=a[la];
				break;
			}
			if(a[la]<b[lb]) ++la; else ++lb;
		}
		if(ans==-1) cout << "NO"; else {
			cout << "YES\n1 " << ans;
		}
		cout << '\n';
	}
}