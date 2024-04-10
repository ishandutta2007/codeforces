
// Problem : E. Divide Square
// Contest : Codeforces - Codeforces Round #665 (Div. 2)
// URL : https://codeforces.com/contest/1401/problem/E
// Memory Limit : 384 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int H, V;
long long F = 0;
const int M = 1000001;
int bit[1000005];
vector<int> add[1000005], rem[1000005], qu[1000005];
pair<pair<int, int>, int> hor[100005], ver[100005];

void upd(int n, int v){
	while(n <= M){
		bit[n] += v;
		n += n&-n;
	}
}

int query(int n){
	int ret = 0;
	while(n){
		ret += bit[n];
		n -= n&-n;
	}
	return ret;
}

pair<long long, long long> solve(){
	fill(bit, bit+M+1, 0);
	for(int i = 0; i<=M; i++){
		rem[i].clear();
		add[i].clear();
		qu[i].clear();
	}
	for(int i = 1; i<=H; i++){
		if(hor[i].first.first == 0){
			upd(hor[i].second+1, 1);
			rem[hor[i].first.second].emplace_back(hor[i].second);
		}
		else{
			add[hor[i].first.first].emplace_back(hor[i].second);
		}
	}
	for(int i = 1; i<=V; i++){
		qu[ver[i].second].emplace_back(i);
	}
	long long V = 0, E = 0;
	for(int i = 0; i<=M-1; i++){
		for(int n : add[i]){
			upd(n+1, 1);
		}
		for(int q : qu[i]){
			long long k = query(ver[q].first.second+1) - query(ver[q].first.first);
			//cout << i << " " << k << "\n";
			V += k;
			E += k-1;
		}
		for(int n : rem[i]){
			upd(n+1, -1);
		}
	}
	//cout << "done" << "\n";
	return make_pair(V, E);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> H >> V;
	for(int i = 1; i<=H; i++){
		cin >> hor[i].second;		
		cin >> hor[i].first.first;
		cin >> hor[i].first.second;
	}
	hor[H+1].second = 0;
	hor[H+1].first.first = 0;
	hor[H+1].first.second = M-1;
	hor[H+2].second = M-1;
	hor[H+2].first.first = 0;
	hor[H+2].first.second = M-1;
	H += 2;
	for(int i = 1; i<=V; i++){
		cin >> ver[i].second;		
		cin >> ver[i].first.first;
		cin >> ver[i].first.second;
	}
	ver[V+1].second = 0;
	ver[V+1].first.first = 0;
	ver[V+1].first.second = M-1;
	ver[V+2].second = M-1;
	ver[V+2].first.first = 0;
	ver[V+2].first.second = M-1;	
	V += 2;
	auto p = solve();
	//swap(hor, ver);
	for(int i = 1; i<=max(H, V); i++){
		swap(hor[i], ver[i]);
	}
	swap(H, V);
	auto q = solve();
	//cout << p.first << " " << p.second << "\n";
	//cout << q.first << " " << q.second << "\n";
	cout << p.second + q.second - p.first + 1 << "\n";
}