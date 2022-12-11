
// Problem : A. C+=
// Contest : Codeforces - Codeforces Global Round 8
// URL : https://codeforces.com/contest/1368/problem/A
// Memory Limit : 512 MB
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
		long long a, b, n;
		cin >> a >> b >> n;
		int cnt = 0;
		while(a <= n && b <= n){
			cnt++;
			if(a > b){
				b += a;
			}
			else{
				a += b;
			}
		}
		cout << cnt << "\n";
	}
}