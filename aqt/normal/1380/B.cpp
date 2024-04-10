
// Problem : Universal Solution
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1380/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

vector<char> let = {'R', 'P', 'S'};
int cnt[3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int N = s.size();
		fill(cnt, cnt+3, 0);
		int ans = 0;
		for(int i = 0; i<N; i++){
			for(int k = 0; k<3; k++){
				if(let[k] == s[i]){
					cnt[k]++;
					if(cnt[k] > cnt[ans]){
						ans = k;
					}
				}
			}
		}
		ans++;
		ans %= 3;
		while(N--){
			cout << let[ans];
		}
		cout << "\n";
	}
}