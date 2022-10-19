#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, k;
int a[111];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, n) cin >> a[i];
		int cnt = 0;
		for(int i = 1; i < n; i++) cnt += (a[i] != a[i-1]);
		if(k == 1){
			if(cnt > 0) cout << "-1" << endl;
			else cout << "1" << endl;
		} else {
			if(cnt == 0) cout << "1" << endl;
			else cout << (cnt + (k - 2)) / (k - 1) << endl;
		}
	}
	return 0;
}