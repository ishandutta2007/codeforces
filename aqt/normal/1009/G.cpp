
// Problem : G. Allowed Letters
// Contest : Codeforces - Educational Codeforces Round 47 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1009/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

string s;
int N;
int msk[100005];
int tot[1<<10];
int fre[1<<10];
int cnt[10];

bool chk(){
	for(int m = 0; m<1<<6; m++){
		int lft = 0;
		for(int i = 0; i<6; i++){
			if(m>>i&1){
				lft += cnt[i];
			}
		}
		if(lft > tot[m]){
			return 0;
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> N;
	fill(msk+1, msk+1+s.size(), 63);
	while(N--){
		int p;
		cin >> p;
		string k;
		cin >> k;
		msk[p] = 0;
		for(char c : k){
			msk[p] |= (1<<(c-'a'));
		}
	}
	N = s.size();
	for(int i = 1; i<=N; i++){
		cnt[s[i-1]-'a']++;		
		for(int m = 0; m<64; m++){
			if(msk[i]&m){
				tot[m]++;
			}
		}
	}
	s.clear();
	if(!chk()){
		cout << "Impossible\n";
		return 0;
	}
	for(int i = 1; i<=N; i++){
		for(int m = 0; m<64; m++){
			if(msk[i]&m){
				tot[m]--;
			}
		}
		for(int c = 0; c<6; c++){
			if(msk[i]&(1<<c) && cnt[c]){
				cnt[c]--;
				//cout << i << " " << c << " " << chk() << "\n";
				if(chk()){
					s.push_back(c+'a');
					break;
				}
				cnt[c]++;
			}
		}
	}
	cout << s;
}