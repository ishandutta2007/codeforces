
// Problem : B. Cow and Friend
// Contest : Codeforces Round #621 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1307/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, X;
		cin >> N >> X;
		set<int> st;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			st.insert(n);
		}
		int ans = INT_MAX/2;
		for(int k : st){
			if(k == X){
				ans = 1;
			}
			else if(k*2 >=X){
				ans = min(ans, 2);
			}
			else if(X%k == 0){
				ans = min(ans, X/k);
			}
			else{
				ans = min(ans, X/k+1);
			}
		}
		cout << ans << "\n";
	}
}