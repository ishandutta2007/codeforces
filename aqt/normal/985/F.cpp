
// Problem : F. Isomorphic Strings
// Contest : Codeforces - Educational Codeforces Round 44 (Rated for Div. 2)
// URL : https://codeforces.com/contest/985/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
string s;
vector<int> pos[30];
vector<long long> hsh[30];
mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1e9+7;
long long pows[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	cin >> s;
	pows[0] = 1;
	const long long sd = uniform_int_distribution<long long> (MOD/2, MOD-1) (rando);	
	for(int i = 1; i<=1000000; i++){
		pows[i] = (pows[i-1] * sd)%MOD;
	}
	for(int i = 1; i<=N; i++){
		pos[s[i-1] - 'a'].emplace_back(i);
	}
	for(int c = 0; c<26; c++){
		hsh[c].emplace_back(0);
		for(int i = 1; i<pos[c].size(); i++){
			hsh[c].emplace_back((hsh[c].back() * sd + pos[c][i] - pos[c][i-1])%MOD);
		}
	}
	while(Q--){
		int l1, l2, len;
		cin >> l1 >> l2 >> len;
		vector<long long> a, b;
		for(int c = 0; c<26; c++){
			int lb = lower_bound(pos[c].begin(), pos[c].end(), l1) - pos[c].begin();
			int ub = lower_bound(pos[c].begin(), pos[c].end(), l1 + len) - pos[c].begin();
			if(lb <= --ub){
				long long t = ((hsh[c][ub] - hsh[c][lb] * pows[ub - lb])%MOD+MOD)%MOD;
				t += (pos[c][lb] - l1 + 1) * pows[1000000];
				t %= MOD;
				a.emplace_back(t);
			}
			else{
				a.emplace_back(0);
			}
			lb = lower_bound(pos[c].begin(), pos[c].end(), l2) - pos[c].begin();
			ub = lower_bound(pos[c].begin(), pos[c].end(), l2 + len) - pos[c].begin();
			if(lb <= --ub){
				long long t = ((hsh[c][ub] - hsh[c][lb] * pows[ub - lb])%MOD+MOD)%MOD;
				t += (pos[c][lb] - l2 + 1) * pows[1000000];
				t %= MOD;
				b.emplace_back(t);
			}
			else{
				b.emplace_back(0);
			}			
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		cout << (a == b ? "YES\n" : "NO\n");
	}
}