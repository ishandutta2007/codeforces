
// Problem : D1. Prefix-Suffix Palindrome (Easy version)
// Contest : Codeforces Global Round 7
// URL : https://codeforces.com/contest/1326/problem/D1
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long hshf[2][1000005], hshr[2][1000005];
long long sd[2] = {1331, 69};
long long wesleysasshole[10] = {2843, 6581,7753,139,4889,7583,389,8273,1433,9203};
long long pows[2][1000005];
const long long MOD = 1e9+7;

pair<long long, long long> gethsh(int l, int r, bool rev){
	if(rev){
		long long h1 = ((hshr[0][l] - hshr[0][r+1] * pows[0][r-l+1])%MOD+MOD)%MOD;
		long long h2 = ((hshr[1][l] - hshr[1][r+1] * pows[1][r-l+1])%MOD+MOD)%MOD;
		return {h1, h2};
	}
	else{
		long long h1 = ((hshf[0][r]-hshf[0][l-1]*pows[0][r-l+1])%MOD+MOD)%MOD;
		long long h2 = ((hshf[1][r]-hshf[1][l-1]*pows[1][r-l+1])%MOD+MOD)%MOD;
		return {h1, h2};
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		sd[0] = ((rand()^rand())+rand()+69*rand())%rand()*rand()%10;
		sd[0] = wesleysasshole[sd[0]];
		string s;
		cin >> s;
		bool p = 1;
		int idx = -1;
		for(int i = 0; i<s.size(); i++){
			if(s[i] != s[s.size()-i-1]){
				p = 0;
			}
			if(p){
				idx = i;
				//cout << i << " " << idx << "\n";
			}
		}
		int N = s.size();
		if(!p){
			pows[0][0] = pows[1][0] = 1;
			for(int i = 1; i<=N; i++){
				hshf[0][i] = hshf[0][i-1] * sd[0] + s[i-1] - 'a' + 1;
				hshf[1][i] = hshf[1][i-1] * sd[1] + s[i-1] - 'a' + 1;
				hshf[0][i] %= MOD;
				hshf[1][i] %= MOD; 
				pows[0][i] = pows[0][i-1] * sd[0] %MOD;
				pows[1][i] = pows[1][i-1] * sd[1] %MOD;
			}
			hshr[0][N+1] = hshr[1][N+1] = 0;
			for(int i = N; i; i--){
				hshr[0][i] = hshr[0][i+1] * sd[0] + s[i-1] - 'a' + 1;
				hshr[1][i] = hshr[1][i+1] * sd[1] + s[i-1] - 'a' + 1;
				hshr[0][i] %= MOD;
				hshr[1][i] %= MOD;
			}
			idx++;
			//cout << idx << "\n";
			int l = 0, r = -1;
			for(int i = idx+1; i<=N-idx; i++){
				if(gethsh(idx+1, i, 0) == gethsh(idx+1, i, 1)){
					l = idx+1, r = i;
				}
			}
			for(int i = idx+1; i<=N-idx; i++){
				//cout << i << " " << N-idx << " " << gethsh(i, N-idx, 0).first << " " << gethsh(i, N-idx, 1).first << "\n";
				if(gethsh(i, N-idx, 0) == gethsh(i, N-idx, 1) && N-idx-i > r-l){
					l = i, r = N-idx;
				}
			}
			//cout << l << " " << r << "\n";
			for(int i = 0; i<=idx-1; i++){
				cout << s[i];
			}
			for(int i = l-1; i<r; i++){
				cout << s[i];
			}
			for(int i = idx-1; i>=0; i--){
				cout << s[i];
			}
			cout << "\n";
		}
		else{
			cout << s << "\n";
		}
	}
}