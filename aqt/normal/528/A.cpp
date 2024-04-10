
// Problem : A. Glass Carving
// Contest : Codeforces - Codeforces Round #296 (Div. 1)
// URL : https://codeforces.com/contest/528/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
char typ[200005];
int idx[200005];
long long ans[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	set<int> h, v;
	h.insert(0), v.insert(0);
	h.insert(M), v.insert(N);
	for(int i = 1; i<=K; i++){
		char c;
		cin >> c;
		typ[i] = (c == 'H');
		cin >> idx[i];
		if(typ[i]){
			h.insert(idx[i]);
		}
		else{
			v.insert(idx[i]);
		}
	}
	int maxh = 0, maxv = 0;
	for(auto it = h.begin(); it != h.end(); ){
		if(*it == M){
			break;
		}
		int c = *it;
		maxh = max(maxh, -c + (*(++it)));
	}
	for(auto it = v.begin(); it != v.end(); ){
		if(*it == N){
			break;
		}
		int c = *it;
		maxv = max(maxv, -c + (*(++it)));
	}
	for(int i = K; i; i--){
		ans[i] = max(ans[i], 1LL*maxv*maxh);
		if(typ[i]){
			h.erase(idx[i]);
			maxh = max(maxh, *(h.lower_bound(idx[i])) - *(--h.lower_bound(idx[i])));
		}
		else{
			v.erase(idx[i]);
			maxv = max(maxv, *(v.lower_bound(idx[i])) - *(--v.lower_bound(idx[i])));			
		}
	}
	for(int i = 1; i<=K; i++){
		cout << ans[i] << "\n";
	}
}