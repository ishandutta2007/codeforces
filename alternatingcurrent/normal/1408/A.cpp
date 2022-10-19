#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int t;
int n;
int a[111], b[111], c[111];
int p[111];

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		rep(i, n) cin >> c[i];
		p[0] = a[0];
		for(int i = 1; i < n-1; i++){
			if(a[i] != p[i-1]) p[i] = a[i];
			else p[i] = b[i];
		}
		if(a[n-1] != p[n-2] && a[n-1] != p[0]) p[n-1] = a[n-1];
		else if(b[n-1] != p[n-2] && b[n-1] != p[0]) p[n-1] = b[n-1];
		else p[n-1] = c[n-1];
		rep(i, n) cout << p[i] << " ";
		cout << endl;
	}
	return 0;
}