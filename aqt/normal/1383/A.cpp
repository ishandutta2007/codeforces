
// Problem : A. String Transformation 1
// Contest : Codeforces - Codeforces Round #659 (Div. 1)
// URL : https://codeforces.com/contest/1383/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
		int N;
		cin >> N;
		string a, b;
		cin >> a >> b;
		bool exist = 1;
		for(int i = 0; i<N; i++){
			if(a[i] > b[i]){
				exist = 0;
			}
		}
		if(!exist){
			cout << -1 << "\n";
			continue;
		}
		int ans = 0;
		for(char c = 'a'; c<='t'; c++){
			int cnt = 0;
			char mn = 'z';
			for(int i = 0; i<N; i++){
				if(a[i] == c && a[i] != b[i]){
					cnt++;
					mn = min(mn, b[i]);
				}
			}
			if(cnt){
				ans++;
				for(int i = 0; i<N; i++){
					if(a[i] == c && a[i] != b[i]){
						a[i] = mn;	
					}
				}
			}
		}
		cout << ans << "\n";
	}
}