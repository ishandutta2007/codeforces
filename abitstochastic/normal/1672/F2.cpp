#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; int T , N , ans[_] , A[_] , B[_];
vector < int > nxt[_] , nxt1[_]; int deg[_];
bool check(int node){
	if(!node) return 1;
	for(int i = 1 ; i <= N ; ++i){nxt1[i].clear(); deg[i] = 0;}
	for(int i = 1 ; i <= N ; ++i)
		for(auto t : nxt[i])
			if(!(t == node || i == node)){nxt1[i].push_back(t); ++deg[t];}
	int cnt = 1; queue < int > q;
	for(int i = 1 ; i <= N ; ++i) if(i != node && deg[i] == 0) q.push(i);
	while(!q.empty()){
		int t = q.front(); q.pop(); ++cnt;
		for(auto x : nxt1[t]) if(!--deg[x]) q.push(x);
	}
	return cnt == N;
}

int main(){
	cin >> T;
	while(T--){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		for(int i = 1 ; i <= N ; ++i) cin >> B[i];
		for(int i = 1 ; i <= N ; ++i) nxt[i].clear();
		for(int i = 1 ; i <= N ; ++i) nxt[B[i]].push_back(A[i]);
		int mx1 = 0 , mx2 = 0;
		for(int i = 1 ; i <= N ; ++i)
			if(nxt[i].size() > nxt[mx1].size()){mx1 = i; mx2 = 0;}
			else if(nxt[i].size() == nxt[mx1].size()) mx2 = i;
		cout << (check(mx1) && check(mx2) ? "AC" : "WA") << endl;
	}
	return 0;
}