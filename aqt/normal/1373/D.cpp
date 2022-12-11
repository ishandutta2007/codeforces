
// Problem : D. Maximum Sum on Even Positions
// Contest : Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1373/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long even[200005], odd[200005];
long long mx[2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		mx[0] = mx[1] = 0;
		for(int i = 1; i<=N; i++){
			even[i] = even[i-1];
			odd[i] = odd[i-1];
			int n;
			cin >> n;
			if(i%2 == 1){
				even[i] += n;
			}
			else{
				odd[i] += n;
			}
		}
		mx[0] = -odd[1]+even[1];
		long long ans = even[N];
		for(int i = 2; i<=N; i++){
			ans = max(ans, even[N]-even[i]+odd[i]+mx[i&1^1]);
			mx[i&1^1] = max(mx[i&1^1], -odd[i]+even[i]);
		}
		cout << ans << "\n";
	}
}