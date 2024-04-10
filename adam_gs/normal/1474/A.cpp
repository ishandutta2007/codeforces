#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {		
		int n;
		cin >> n;
		string a;
		cin >> a;
		string b="";
		b+=a[0]+1;
		for(int i=1; i<n; ++i) {
			b+=a[i];
			if(a[i]+1!=b[i-1]) b[i]+=1;
		}
		rep(i, n) cout << b[i]-a[i];
		cout << '\n';
	}
}