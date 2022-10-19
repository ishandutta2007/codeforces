#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
int rk[50050][5];

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			rep(j, 5)
				cin >> rk[i][j];
		int nowbest = 0;
		for(int i = 1; i < n; i++){
			int cnt = 0;
			rep(j, 5)
				if(rk[nowbest][j] > rk[i][j])
					cnt++;
			if(cnt >= 3)
				nowbest = i;
		}
		bool ok = 1;
		rep(i, n){
			if(i == nowbest)
				continue;
			int cnt = 0;
			rep(j, 5)
				if(rk[nowbest][j] > rk[i][j])
					cnt++;
			if(cnt >= 3){
				ok = 0;
				break;
			}
		}
		if(ok){
			cout << nowbest + 1 << endl;
		} else {
			cout << "-1" << endl;
		}
	}
	return 0;
}