#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

string a, b, c;
int n;

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> a >> b >> c;
		n = a.size();
		bool ok = 1;
		rep(i, n){
			ok &= ((a[i] == c[i]) || (b[i] == c[i]));
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}