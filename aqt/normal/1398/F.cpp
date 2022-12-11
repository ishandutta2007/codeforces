
// Problem : F. Controversial Rounds
// Contest : Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1398/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int pre[2][1000005];
int nxt[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> s;
	bool all_ = 1;
	for(int i = 1; i<=N; i++){
		if(s[i-1] == '?'){
			
		}
		else{
			all_ = 0;
			pre[s[i-1]-'0'][i]++;
		}
		pre[0][i] += pre[0][i-1];
		pre[1][i] += pre[1][i-1];
	}
	if(all_){
		for(int i = 1; i<=N; i++){
			cout << N/i << " ";
		}
		return 0;
	}
	int crnt = 2, idx = 0;
	nxt[0] = 1;
	for(int i = 1; i<=N; i++){
		if(s[i-1] != '?' && crnt != s[i-1] - '0'){
			idx = i;
			for(int j = i-1; j > 0; j--){
				if(s[j-1] != '?'){
					break;
				}
				idx = j;
			}
			crnt = s[i-1] - '0';
			nxt[i] = idx;
		}
		else{
			nxt[i] = nxt[i-1];
		}
	}
	for(int n = 1; n<=N; n++){
		int idx = 1;
		int out = 0;
		//cout << n << endl;
		while(idx+n-1 <= N){
			//cout << idx << "\n";
			//cout << "index: " << idx+n-1 << " " << idx-1 << "\n";
			//cout << pre[0][idx+n-1] - pre[0][idx-1] << " " << pre[1][idx+n-1] - pre[1][idx-1] << "\n";
			if(pre[0][idx+n-1] - pre[0][idx-1] == 0 || pre[1][idx+n-1] - pre[1][idx-1] == 0){
				out++;
				idx += n;
				//cout << "bing" << "\n";
			}
			else{
				idx = nxt[idx+n-1];
				//cout << "bang" << "\n";
			}
		}
		cout << out << " ";
	}
}