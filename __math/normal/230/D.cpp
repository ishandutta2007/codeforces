#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 1000000000+100000;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

map<int,int> t[100001];
int n,m;
vector<Pii> e[100001];
typedef Pii P;
int cost[100001];
int cost2[100001];

int dijkstra(int s){
	fill(cost,cost+ n,INF);
	fill(cost2,cost2+ n,INF);
	
	priority_queue<P,vector<P>,greater<P> > q;
	int start_cost = 0;
	if(t[s].find(start_cost) != t[s].end()){
		start_cost = t[s][start_cost];
	}
	cost2[s] = cost[s] = start_cost;
	q.push(P(start_cost,s));

	while(!q.empty()){
		P p = q.top(); q.pop();
		int v = p.second;
		if(cost[v] < p.first) continue;
		for(int i = 0; i < sz(e[v]); i++){
			Pii& pii = e[v][i];
			int next = cost[v] + pii.second;
			if(cost2[pii.first] > next){
				cost2[pii.first] = next;
			}
			if(t[pii.first].find(next) != t[pii.first].end()){
				next = t[pii.first][next];
			}
			if(cost[pii.first] > next){
				cost[pii.first] = next;
				q.push(P(cost[pii.first],pii.first));
			}
		}
	}

	return cost2[n-1];
}

int main(){
	cin>>n>>m;
	FOR(i,m){
		int a,b,c; cin>>a>>b>>c;
		a--;b--;
		e[a].push_back(Pii(b,c));
		e[b].push_back(Pii(a,c));
	}
	FOR(i,n){
		int k; cin>>k;
		static int buf[100000];
		FOR(l,k){
			int x; cin>>x;
			buf[l] = x;
		}
		int lst = buf[k-1] + 1;
		map<int,int> &mp = t[i];
		for(int j = k-1; j >= 0; j--){
			mp[buf[j]] = lst;
			if(!(j > 0 && buf[j] -1 == buf[j-1])){
				lst = buf[j-1] + 1;
			}
		}
	}

	int ans = dijkstra(0);

	if(ans == INF){
		puts("-1");
	} else {
		cout << ans << endl;
	}

	return 0;
}