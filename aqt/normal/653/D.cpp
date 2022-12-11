
// Problem : D. Delivery Bears
// Contest : Codeforces - IndiaHacks 2016 - Online Edition (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/653/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, X;
vector<int> graph[55];
int u[1005], v[1005];
long long c[1005], f[1005];
int ptr[55], lvl[55];
const long long inf = LLONG_MAX/2;

bool bfs(){
	fill(lvl, lvl+1+N, 0);
	queue<int> qu;
	qu.push(1);
	lvl[1] = 1;
	while(qu.size()){
		int n = qu.front();
		qu.pop();
		for(int e : graph[n]){
			if(f[e] && !lvl[v[e]]){
				//cout << f[e] << "\n";
				lvl[v[e]] = lvl[u[e]] + 1;
				qu.push(v[e]);
			}
		}
	}
	return lvl[N];
}

long long dfs(int n, long long b){
	//cout << " " << n << " " << b << endl;
	if(!b || n == N){
		return b;
	}
	for(; ptr[n]<graph[n].size(); ptr[n]++){
		int e = graph[n][ptr[n]];
		if(lvl[n] + 1 != lvl[v[e]] || !f[e]){
			continue;
		}
		long long t = dfs(v[e], min(f[e], b));
		//cout << t << " " << b << endl;
		if(!t){
			continue;
		}
		f[e] -= t;
		f[e^1] += t;
		return t;
	}
	//cout << "bad: " << n << endl;
	return 0;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> X;
	for(int i = 0; i<M; i++){
		int a, b, w;
		cin >> a >> b >> w;
		u[2*i] = a;
		v[2*i] = b;
		c[2*i] = w;
		u[2*i+1] = b;
		v[2*i+1] = a;
		graph[a].push_back(2*i);
		graph[b].push_back(2*i+1);
	}
	long double l = 1e-7, r = 1e6, ans = 0;
	for(int it = 0; it<100; it++){
		long double mid = (l+r)/2;
		//cout << mid << "\n";
		for(int i = 0; i<2*M; i+=2){
			f[i] = floor(c[i]/mid);
			f[i^1] = floor(c[i^1]/mid);
			//cout << f[i] << " " << f[i^1] << "\n";
		}
		long long tot = 0;
		while(1){
			if(!bfs()){
				break;
			}
			fill(ptr+1, ptr+1+N, 0);
			//cout << dfs(1, inf) << "\n";
			while(long long p = dfs(1, inf)){
				tot += p;
			}
		}
		//cout << tot << " " << mid << endl;
		if(tot >= X){
			l = mid;
			ans = mid;
		}
		else{
			r = mid;
		}
	}
	cout << setprecision(9) << X*ans << "\n";
}