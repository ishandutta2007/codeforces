
// Problem : E. Water Level
// Contest : Codeforces - Codeforces Round #689 (Div. 2, based on Zed Code Competition)
// URL : https://codeforces.com/contest/1461/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long k, l, r, t, x, y;
bool vis[3000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> l >> r >> t >> x >> y;
	k -= l;
	r -= l;
	if(x <= y){
		while(t){
			//cout << t << " " << k << "\n";
			if(k/x >= t){
				break;
			}
			if(vis[k%x]){
				break;
			}
			t -= k/x;
			k %= x;
			vis[k] = 1;
			if(k + y > r || k + y - x < 0){
				cout << "No\n";
				return 0;
			}
			k += y;
		}
		cout << "Yes\n";
	}
	else{
		while(t && k + y > r){
			t--;
			k -= x;
		}
		if(k < 0){
			cout << "No\n";
			return 0;
		}
		k += y;
		//cout << t << " " << k << "\n";
		if((k-k%x)/(x-y) >= t){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}