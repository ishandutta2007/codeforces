#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
bool ok[1010][6];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			rep(j, 5)
				cin >> ok[i][j];
		bool yes = 0;
		rep(d0, 5){
			rep(d1, d0){
				int cnt0, cnt1, cnt01;
				cnt0 = cnt1 = cnt01 = 0;
				rep(i, n){
					if(ok[i][d0])
						cnt0++;
					if(ok[i][d1])
						cnt1++;
					if(ok[i][d0] && ok[i][d1])
						cnt01++; 
				}
				if(cnt0 + cnt1 - cnt01 == n && cnt0 - cnt01 <= n / 2 && cnt1 - cnt01 <= n / 2)
					yes = 1;
			}
		}
		if(yes)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	} 
	return 0;
}