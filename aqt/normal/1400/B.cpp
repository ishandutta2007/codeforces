
// Problem : B. RPG Protagonist
// Contest : Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1400/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int A, B;
		cin >> A >> B;
		int CA, CB;
		cin >> CA >> CB;
		int WA, WB;
		cin >> WA >> WB;
		if(WA > WB){
			swap(CA, CB);
			swap(WA, WB);
		}
		int ans = 0;
		for(int i = 0; i<=CA; i++){
			if(1LL*i*WA > A){
				break;
			}
			if(B/WA + i > CA){
				ans = max(ans, CA + min(CB, (A - i*WA)/WB + (B - (CA-i)*WA)/WB));
			}
			else{
				ans = max(ans, B/WA + i + min(CB, (A - i*WA)/WB + (B - (B/WA)*WA)/WA));
			}
		}
		cout << ans << "\n";
	}
}