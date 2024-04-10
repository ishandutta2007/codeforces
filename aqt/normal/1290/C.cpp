
// Problem : C. Prefix Enlightenment
// Contest : Codeforces Round #616 (Div. 1)
// URL : https://codeforces.com/contest/1290/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> graph[300005];
string s;
int par[600005];
long long sz[600005];
bool tkn[600005];

int getrt(int n){
	return par[n] = (par[n] == n ? n : getrt(par[n]));
}

long long rem(int n){
	if(tkn[n]){
		tkn[n] = 0;
		return sz[n];
	}
	return 0;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> s;
	for(int k = 1; k<=K; k++){
		int n;
		cin >> n;
		for(int i = 1; i<=n; i++){
			int p;
			cin >> p;
			graph[p].emplace_back(k);
		}
		sz[k] = 1;
	}
	for(int k = 1; k<=2*K; k++){
		par[k] = k;
		tkn[k] = (k > K);
	}
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		if(graph[i].size() == 1){
			int p1 = getrt(graph[i][0]);
			int p2 = getrt(graph[i][0] + K);		
			if(s[i-1] == '1'){
				swap(p1, p2);
			}
			ans -= rem(p1);
			ans -= rem(p2);
			sz[p2] = N + 1;
			if(sz[p1] < sz[p2]){
				ans += sz[p1];
				tkn[p1] = 1;
			}
			else{
				ans += sz[p2];
				tkn[p2] = 1;
			}
		}
		else if(graph[i].size() == 2){
			int p10 = getrt(graph[i][0]), p11 = getrt(graph[i][1]);
			int p20 = getrt(graph[i][0] + K), p21 = getrt(graph[i][1] + K);
			if(s[i-1] == '0'){
				swap(p10, p20);
			}
			if(p10 != p11){
				ans -= rem(p10);
				ans -= rem(p11);
				par[p10] = p11;
				sz[p11] += sz[p10];
				ans -= rem(p20);
				ans -= rem(p21);
				par[p20] = p21;
				sz[p21] += sz[p20];				
				if(sz[p11] < sz[p21]){
					ans += sz[p11];
					tkn[p11] = 1;
				}
				else{
					ans += sz[p21];
					tkn[p21] = 1;
				}
			}
		}
		cout << ans << "\n";
	}
}