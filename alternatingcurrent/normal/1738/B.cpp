#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int t;
int n, k;
int s[100100];

int main(){
	ios::sync_with_stdio(false);
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = n-k; i < n; ++i)
			cin >> s[i];
		
		for(int i = n-1; i > n-k; --i)
			s[i] -= s[i-1];
		
		bool ok = 1;
		
		for(int i = n-k+1; i < n-1; ++i)
			if(s[i+1] < s[i])
				ok = 0;
		
		if(k > 1)
			ok &= (1ll * s[n-k+1] * (n-k+1) >= (ll)s[n-k]);
		
		cout << (ok ? "YES" : "NO") << endl;
	}
	
	return 0;
}