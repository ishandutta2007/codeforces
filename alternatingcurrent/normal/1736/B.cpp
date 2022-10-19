#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int t;
int n;
int a[100100], b[100100];

int main(){
	ios::sync_with_stdio(false);
	
	cin >> t;
	while(t--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		
		b[0] = a[0], b[n] = a[n-1];
		for(int i = 1; i < n; ++i)
			b[i] = a[i-1] * a[i] / __gcd(a[i], a[i-1]);
		
		bool ok = 1;
		rep(i, n)
			if(a[i] != __gcd(b[i], b[i+1]))
				ok = 0;
		
		cout << (ok ? "YES\n" : "NO\n");
	}
	
	return 0;
}