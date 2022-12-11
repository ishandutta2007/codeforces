
// Problem : C. Johnny and Megan's Necklace
// Contest : Codeforces - Codeforces Round #647 (Div. 1) - Thanks, Algo Muse!
// URL : https://codeforces.com/contest/1361/problem/C
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[1<<20];
int par[1<<20];
int dgr[1<<20];
vector<int> graph[1<<20];
bool used[1<<20];
vector<int> out;
int ans = 0;

int getrt(int n){
	return par[n] = (par[n] == n ? n : getrt(par[n]));
}

void dfs(int n){
	while(graph[n].size()){
		int k = graph[n].back();
		graph[n].pop_back();
		if(!used[abs(k)]){
			used[abs(k)] = 1;			
			if(k < 0){
				dfs(arr[-k].first%(1<<ans));
			}
			else{
				dfs(arr[k].second%(1<<ans));
			}
			out.push_back(k);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int a, b;
		cin >> a >> b;
		arr[i].first = a, arr[i].second = b;
	}
	for(int k = 0; k<=20; k++){
		for(int i = 0; i<(1<<k); i++){
			par[i] = i;
			dgr[i] = 0;
		}
		for(int i = 1; i<=N; i++){
			int a = arr[i].first % (1<<k);
			int b = arr[i].second % (1<<k);
			dgr[a]++;
			dgr[b]++;
			if(getrt(a) != getrt(b)){
				par[getrt(a)] = getrt(b);
			}
		}
		bool good = 1;
		int rt = -1;
		for(int i = 0; i<(1<<k); i++){
			if(!dgr[i]){
				continue;
			}
			if(dgr[i]%2 == 1){
				good = 0;
			}
			else if(rt == -1){
				rt = i;
			}
			else if(getrt(rt) != getrt(i)){
				good = 0;
			}
		}
		if(good){
			ans = k;
		}
	}
	int k = ans;
	int rt = -1;
	for(int i = 1; i<=N; i++){
		int a = arr[i].first % (1<<k);
		int b = arr[i].second % (1<<k);
		graph[a].push_back(i);
		graph[b].push_back(-i);
		rt = a;
	}
	dfs(rt);
	cout << ans << "\n";	
	for(int n : out){
		if(n < 0){
			cout << -2*n-1 << " " << -2*n << " ";
		}
		else{
			cout << 2*n << " " << 2*n-1 << " ";
		}
	}
}