#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n, k;
string ans[44];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> k;
		if((n + 1) / 2 < k)
			cout << "-1" << endl;
		else {
			rep(i, n){
				ans[i] = "";
				rep(j, n)
					ans[i] += '.';
			}
			for(int i = 0; i <= k * 2 - 2; i += 2){
				ans[i][i] = 'R';
			}
			rep(i, n)
				cout << ans[i] << endl;
		}
	}
	return 0;
}