
// Problem : A. Dreamoon and Stairs
// Contest : Codeforces - Codeforces Round #272 (Div. 2)
// URL : https://codeforces.com/contest/476/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	int ans = N+1;
	for(int i = 0; i<=N; i++){
		int two = N-i;
		if(two%2 == 0 && (i + two/2)%M == 0){
			ans = min(ans, i+two/2);
		}
	}
	if(ans > N){
		ans = -1;
	}
	cout << ans;
}