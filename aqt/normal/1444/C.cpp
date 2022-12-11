
// Problem : C. Team-Building
// Contest : Codeforces - Codeforces Round #680 (Div. 1, based on Moscow Team Olympiad)
// URL : https://codeforces.com/problemset/problem/1444/C
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
bool bi[500005];
int clr[500005];
int sz[500005];
int dsu[500005];
int dis[500005];
vector<int> stk;
map<pair<int, int>, vector<pair<int, int>>> mp;

pair<int, int> getrt(int n){
	if(n == dsu[n]){
		return make_pair(n, 0);
	}
	auto p = getrt(dsu[n]);
	p.second ^= dis[n];
	return p;
}

bool unite(int a, int b){
	auto p = getrt(a), q = getrt(b);
	//cout << p.first << " " << q.first << "\n";
	//cout<< p.second << " " << q.second << "\n";
	if(p.first == q.first){
		return p.second != q.second;
	}
	if(sz[p.first] >= sz[q.first]){
		dis[q.first] = (q.second ^ p.second ^ 1);
		dsu[q.first] = p.first;
		sz[p.first] += sz[q.first];
		stk.push_back(q.first);
	}
	else{
		dis[p.first] = (p.second ^ q.second ^ 1);
		dsu[p.first] = q.first;
		sz[q.first] += sz[p.first];
		stk.push_back(p.first);
	}
	return 1;
}

void rollback(){
	int n = stk.back();
	stk.pop_back();
	auto p = getrt(n);
	sz[p.first] -= sz[n];
	dsu[n] = n;
	dis[n] = 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	fill(bi+1, bi+1+K, 1);
	for(int i= 1; i<=N; i++){
		cin >> clr[i];
		dsu[i] = i;
		sz[i] = 1;
	}
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		//cout << "hi\n";
		if(clr[a] == clr[b]){
			if(!unite(a, b)){
				bi[clr[a]] = 0;
			}
		}
		else if(clr[a] < clr[b]){
			mp[make_pair(clr[a], clr[b])].emplace_back(a, b);
		}
		else{
			mp[make_pair(clr[b], clr[a])].emplace_back(a, b);
		}
	}
	long long ans = 1LL*K*(K-1)/2;
	int cnt = 0;
	for(int i = 1; i<=K; i++){
		cnt += !bi[i];
	}
	ans -= 1LL*cnt*(K-1+K-cnt)/2;
	stk.clear();
	for(auto p : mp){
		if(bi[p.first.first] && bi[p.first.second]){
			for(auto e : p.second){
				if(!unite(e.first, e.second)){
					ans--;
					break;
				}
			}
			while(stk.size()){
				rollback();
			}
		}
	}
	cout << ans;
}