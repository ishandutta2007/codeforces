#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int ans[111][111];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		memset(ans, 0, sizeof(ans));
		if(n % 2 == 1){
			rep(i, n){
				for(int j = (i+1) % n, cnt = 0; cnt < (n / 2); j = (j + 1) % n, cnt++) ans[i][j] = 1, ans[j][i] = -1;
			}
		} else {
			rep(i, n){
				for(int j = (i+1) % n, cnt = 0; cnt < ((n - 1) / 2); j = (j + 1) % n, cnt++) ans[i][j] = 1, ans[j][i] = -1;
			}
		}
		rep(i, n){
			for(int j = i+1; j < n; j++){
				cout << ans[i][j] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}