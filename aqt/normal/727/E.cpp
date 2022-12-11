
// Problem : E. Games on a CD
// Contest : Codeforces - Technocup 2017 - Elimination Round 1 (Unofficially Open for Everyone, Rated for Div. 2)
// URL : https://codeforces.com/contest/727/problem/E
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

int N, K, M;
string s;
const long long MOD = 1e9+7;
long long sd[2];
long long hsh[2][2000005];
long long pows[2][2000005];
pair<long long, long long> arr[2000005];
map<pair<long long, long long>, int> mp;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	cin >> s;
	s += s;
	sd[0] = uniform_int_distribution<long long>(MOD/2, MOD) (rando);
	sd[1] = uniform_int_distribution<long long>(MOD/2, MOD) (rando);
	pows[0][0] = pows[1][0] = 1;
	for(int i = 1; i<=2*N*K; i++){
		hsh[0][i] = (hsh[0][i-1] * sd[0] + s[i-1])%MOD;
		hsh[1][i] = (hsh[1][i-1] * sd[1] + s[i-1])%MOD;
		pows[0][i] = (pows[0][i-1] * sd[0])%MOD;
		pows[1][i] = (pows[1][i-1] * sd[1])%MOD;
	}
	cin >> M;
	for(int i = 1; i<=M; i++){
		cin >> s;
		for(char c : s){
			arr[i].first = (arr[i].first * sd[0] + c) % MOD;
			arr[i].second = (arr[i].second * sd[1] + c) % MOD;
		}
	}
	for(int s = 0; s<K; s++){
		mp.clear();
		for(int i = s+K, c = 0; i<=s+N*K; i+=K, c++){
			long long p1 = (hsh[0][i] - hsh[0][i-K] * pows[0][K]) % MOD;
			p1 += MOD, p1 %= MOD;
			long long p2 = (hsh[1][i] - hsh[1][i-K] * pows[1][K]) % MOD;
			p2 += MOD, p2 %= MOD;
			mp[make_pair(p1, p2)] = c;
		}
		vector<int> ans(N);
		int cnt = 0;
		for(int i= 1; i<=M; i++){
			if(mp.count(arr[i])){
				ans[mp[arr[i]]] = i;
				cnt++;
			}
		}
		if(cnt == N){
			cout << "YES\n";
			for(int n : ans){
				cout << n << " ";
			}
			exit(0);
		}
	}
	cout << "NO\n";
}