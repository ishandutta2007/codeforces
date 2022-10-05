#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

vector< int > g[N];
int n, k, dist[N], mx, was[N];
queue< int > q;
int main(){
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int i = 1; i <= n; i++)
		if(g[i].size() == 1){
			was[i] = 1;
			q.push(i);
		}
    while(!q.empty()){
    	int v = q.front();
    	q.pop();
    	mx = dist[v];
    	for(auto to : g[v])
    		if(!was[to]){
    			dist[to] = dist[v] + 1;
    			was[to] = 1;
    			q.push(to);
    		}
    }
    if(k != mx)
    	cout << "No", exit(0);
    for(int v = 1; v <= n; v++){
    	if(g[v].size() == 1)
    		continue;
        bool ok = 1;
        int cntl = 0, cntp = 0;
        for(auto to: g[v]){
    		if(dist[to] == dist[v] - 1)
    			cntl++;
    		else
    		if(dist[to] == dist[v] + 1)
    			cntp++;
    		else
    			ok = 0;
    	}
    	if(ok && cntl >= 3 && (cntp == 1 || (cntp == 0 && dist[v] == mx)))
    		continue;
    	cout << "No";
    	return 0;
    }
    cout << "Yes";
    return 0;
    return 0;
}