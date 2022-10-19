#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[10010];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		bool ok = 1;
		rep(i, n - 1)
			if(a[i + 1] < a[i])
				ok = 0;
		cout << (ok ? "NO" : "YES") << endl;
	}
	return 0;
}