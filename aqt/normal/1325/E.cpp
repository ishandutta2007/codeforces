
// Problem : E. Ehab's REAL Number Theory Problem
// Contest : Codeforces Round #628 (Div. 2)
// URL : https://codeforces.com/contest/1325/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, M = 1000000;
vector<pair<int, int>> graph[1000005];
vector<int> primes;
bool sieve[1000005];
bool tkn[100005];
int dist[1000005];
int u[100005], v[100005];
queue<int> qu;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 2; i<=M; i++){
		for(int j = 2*i; j<=M; j+=i){
			sieve[j] = 1;
		}
		if(!sieve[i]){
			primes.emplace_back(i);
		}
	}
	for(int i =1 ; i<=N; i++){
		int n;
		cin >> n;
		if(!sieve[n]){
			graph[n].push_back({1, i});
			graph[1].push_back({n, i});
			u[i] = 1, v[i] = n;
			continue;
		}
		for(auto p : primes){
			if(n%(p*p*p) == 0){
				int cnt = 0;
				while(n%p == 0){
					n /= p;
					cnt ^= 1;
				}
				cnt = (cnt ? p : 1);
				graph[cnt].push_back({1, i});
				graph[1].push_back({cnt, i});
				u[i] = 1, v[i] = cnt;
				break;
			}
			else if(n%(p*p) == 0){
				n /= p*p;
				graph[n].push_back({1, i});
				graph[1].push_back({n, i});
				u[i] = n, v[i] = 1;
				break;
			}
			else if(n%p == 0){
				n /= p;
				int s = sqrt(n);
				if(s*s == n){
					graph[p].push_back({1, i});
					graph[1].push_back({p, i});
				}
				graph[n].push_back({p, i});
				graph[p].push_back({n, i});
				u[i] = n, v[i] = p;
				break;
			}
		}
	}
	/*
	for(int i = 1; i<=N; i++){
		cout << u[i] << " " << v[i] << "\n";
	}
	*/
	primes.push_back(1);
	sort(primes.begin(), primes.end());
	int ans = INT_MAX/2;
	for(auto s : primes){
		if(s > 1000){
			break;
		}
		fill(tkn+1, tkn+1+N, 0);
		fill(dist+1, dist+1+M, INT_MAX>>2);
		dist[s] = 0;
		qu.push(s);
		while(qu.size()){
			int n = qu.front();
			qu.pop();
			for(auto e : graph[n]){
				if(dist[e.first] > dist[n] + 1){
					dist[e.first] = dist[n] + 1;
					tkn[e.second] = 1;
					qu.push(e.first);
				}
			}
		}
		//cout << " " << s << "\n";
		for(int i = 1; i<=N; i++){
			if(!tkn[i]){
				//cout << i << " " << dist[u[i]] + dist[v[i]] << "\n";
				ans = min(ans, dist[u[i]] + dist[v[i]] + 1);
			}
		}
	}
	if(ans == INT_MAX/2){
		ans = -1;
	}
	cout << ans << "\n";
}