
// Problem : E. Largest Beautiful Number
// Contest : Educational Codeforces Round 39 (Rated for Div. 2)
// URL : https://codeforces.com/contest/946/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
string s;

void solve(){
	//cout << N << " " << s.size() << endl;
	int msk = 0;
	for(int i = N-1; i>=0; i--){
		msk ^= (1<<(s[i]-'0'));
	}
	for(int i = N-1; i>=0; i--){
		msk ^= (1<<(s[i]-'0'));
		for(int d = (s[i]-'0')-1; d>=0; d--){
			msk ^= (1<<d);
			if(__builtin_popcount(msk) <= N-i-1){
				//cout << i << " " << msk << "\n";
				for(int j = 0; j<i; j++){
					cout << s[j];
				}
				cout << d;
				for(int j = i+1; j<N-__builtin_popcount(msk); j++){
					cout << 9;
				}
				for(int k = 9; k>=0; k--){
					if(msk>>k&1){
						msk ^= (1<<k);
						cout << k;
					}
				}
				cout << "\n";
				return;
			}
			msk ^= (1<<d);
		}
	}
	assert(0);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> s;
		bool sp = s[0] == '1';
		N = s.size();
		for(int i = 1; i<N-1; i++){
			sp &= s[i] == '0';
		}
		if(sp && (s[N-1] == '0' || s[N-1] == '1')){
			int k = N-2;
			for(int i = 0; i<k; i++){
				cout << 9;
			}
			cout << "\n";
		}
		else{
			solve();
		}
	}
}