
// Problem : E. Bear and Forgotten Tree 2
// Contest : IndiaHacks 2016 - Online Edition (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/653/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
unordered_set<int> st[300005];
int par[300005];
bool isbad[300005];

int getrt(int n){
	return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=N; i++){
		par[i] = i;
	}
	int cnt = 0;
	for(int i =1 ; i<=M; i++){
		int a, b;
		cin >> a >> b;
		if(b < a){
			swap(a, b);
		}
		if(a == 1){
			isbad[b] = 1;
			cnt++;
			continue;
		}
		st[a].insert(b);
	}
	if(N-cnt-1 < K){
		cout << "impossible\n";
		return 0;
	}
	int C = N-1;
	for(int i = 2; i<=N; i++){
		for(int j = i+1; j<=N; j++){
			if(!st[i].count(j)){
				isbad[getrt(j)] &= isbad[getrt(i)];
				par[getrt(i)] = getrt(j);
				C--;
				if(st[i].size() > st[j].size()){
					swap(st[i], st[j]);
				}
				unordered_set<int> t;
				for(int n : st[i]){
					if(st[j].count(n)){
						t.insert(n);						
					}
				}
				st[j] = t;
				break;
			}
		}
	}
	if(C > K){
		cout << "impossible\n";
		return 0;
	}
	for(int i = 1; i<=N; i++){
		if(getrt(i) == i && isbad[i]){
			cout << "impossible\n";
			return 0;
		}
	}
	cout << "possible";
}