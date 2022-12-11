
// Problem : E2. Reading Books (hard version)
// Contest : Codeforces - Codeforces Round #653 (Div. 3)
// URL : https://codeforces.com/contest/1374/problem/E2
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<pair<long long, int>> typ[4];
vector<long long> pre[4];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=N; i++){
		int v, a, b;
		cin >> v >> a >> b;
		int t = 2*a + b;
		typ[t].emplace_back(v, i);
	}
	for(int t = 1; t<4; t++){
		sort(typ[t].begin(), typ[t].end());
		pre[t].push_back(0);
		for(auto n : typ[t]){
			pre[t].push_back(pre[t].back() + n.first);
		}
	}	
	//cout << "here1" << endl;
	long long ans = LLONG_MAX/2;
	int idx = -1;
	set<pair<long long, int>> stgood;
	set<pair<long long, int>> stbad;
	long long stgoodval = 0;
	for(auto n : typ[3]){
		stgood.insert(n);
		stgoodval += n.first;
	}
	for(int k = K+1; k<=typ[1].size(); k++){
		stgood.insert(typ[1][k-1]);
		stgoodval += typ[1][k-1].first;
	}
	for(int k = K+1; k<=typ[2].size(); k++){
		stgood.insert(typ[2][k-1]);
		stgoodval += typ[2][k-1].first;
	}
	for(auto n : typ[0]){
		stgood.insert(n);
		stgoodval += n.first;
	}
	//cout << "here2" << endl;
	for(int k = 0; k<=K; k++){
		while(stbad.size() && (int) (stgood.size()) < M-k-2*(K-k)){
			stgood.insert(*stbad.begin());
			stgoodval += (*stbad.begin()).first;
			stbad.erase(stbad.begin());
		}
		while(stgood.size() && (int) (stgood.size()) > M-k-2*(K-k)){
			//cout << stgood.size() << " " << (*(--stgood.end())).first << "\n";
			stbad.insert(*(--stgood.end()));
			stgoodval -= (*(--stgood.end())).first;
			stgood.erase(--stgood.end());
		}
		while(stgood.size() && stbad.size() && stgood.rbegin()->first > stbad.begin()->first){
			stgoodval -= stgood.rbegin()->first;
			stgoodval += stbad.begin()->first;
			stbad.insert(*(--stgood.end()));
			stgood.insert(*stbad.begin());
			stbad.erase(stbad.begin());
			stgood.erase(--stgood.end());
		}
		//cout << "bing" << endl;
		if(k <= typ[3].size() && K-k <= min(typ[1].size(), typ[2].size()) && (int) (stgood.size()) == M - k - 2*(K-k)){
			if(ans > stgoodval + pre[3][k] + pre[1][K-k] + pre[2][K-k]){
				//cout << stgood.begin()->first << " " << stgoodval << " " << pre[3][k] << " " << pre[1][K-k] << " " << pre[2][K-k] << "\n";
				ans = stgoodval + pre[3][k] + pre[1][K-k] + pre[2][K-k];
				idx = k;
			}
		}
		if(k < typ[3].size() && stgood.count(typ[3][k])){
			stgoodval -= typ[3][k].first;
			stgood.erase(typ[3][k]);
		}
		else if(k < typ[3].size() && stbad.count(typ[3][k])){
			stbad.erase(typ[3][k]);
		}
		//cout << "bang" << endl;
		if(K-k && K-k <= typ[1].size()){
			stgood.insert(typ[1][K-k-1]);
			stgoodval += typ[1][K-k-1].first;
		}
		if(K-k && K-k <= typ[2].size()){
			stgood.insert(typ[2][K-k-1]);
			stgoodval += typ[2][K-k-1].first;
		}
	}
	//cout << "here3" << endl;
	if(ans == LLONG_MAX/2){
		cout << -1 << "\n";
		return 0;
	}
	vector<int> out;
	long long chk = 0;
	for(int k = 1; k<=idx; k++){
		out.push_back(typ[3][k-1].second);
		chk += typ[3][k-1].first;
	}
	vector<pair<long long, int>> srt = typ[0];
	for(int k = 1; k<=K-idx; k++){
		out.push_back(typ[2][k-1].second);
		chk += typ[2][k-1].first;
		out.push_back(typ[1][k-1].second);
		chk += typ[1][k-1].first;
	}
	for(int k = K-idx+1; k<=typ[2].size(); k++){
		srt.push_back(typ[2][k-1]);
	}
	for(int k = K-idx+1; k<=typ[1].size(); k++){
		srt.push_back(typ[1][k-1]);
	}
	for(int k = idx+1; k<=typ[3].size(); k++){
		srt.push_back(typ[3][k-1]);
	}
	sort(srt.begin(), srt.end());
	for(int i = 1; i<=M-idx-(K-idx)*2; i++){
		out.push_back(srt[i-1].second);
		chk += srt[i-1].first;
	}
	//assert(chk == ans);
	cout << ans << "\n";
	for(int n : out){
		cout << n << " ";
	}
}