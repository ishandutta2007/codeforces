#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		int n, k;
		string s;
		cin >> n >> k >> s;
		static int cnt[222];
		memset(cnt, 0, sizeof(cnt));
		rep(i, n)
			cnt[s[i] - 'a']++;
		
		rep(i, k){
			int j = 0;
			for(j = 0; j < min(26, n/k); ++j){
				if(!cnt[j])
					break;
				--cnt[j];
			}
			cout << (char)('a'+j);
		}
		cout << "\n";
	}
	
	return 0;
}