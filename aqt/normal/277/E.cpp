
// Problem : E. Binary Tree on Plane
// Contest : Codeforces - Codeforces Round #170 (Div. 1)
// URL : https://codeforces.com/contest/277/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int u[500000], v[500000], f[500000];
long double c[500000];
pair<int, int> arr[500];
vector<int> graph[1005];
bool inqu[1005];
long double dist[1005];
int par[1005];

void addedge(int a, int b, int _f, long double _c){
	//cout << "edge: " << a << " " << b << " " << _f << " " << _c << endl;
	u[M] = a;
	v[M] = b;
	f[M] = _f;
	c[M] = _c;
	graph[u[M]].push_back(M);
	M++;
	u[M] = b;
	v[M] = a;
	c[M] = -_c;
	graph[u[M]].push_back(M);
	M++;
}

long double spfa(){
	fill(inqu, inqu+2*N+2, 0);
	fill(dist, dist+2*N+2, 100000);
	queue<int> qu;
	qu.push(0);
	dist[0] = 0;
	while(qu.size()){
		int n = qu.front();
		//cout << n << " " << dist[n] << "\n";
		qu.pop();
		inqu[n] = 0;
		for(int e : graph[n]){
			if(f[e] && dist[v[e]] > dist[n] + c[e]){
				//cout << e << " " << f[e] << " " << v[e] << " " << c[e] << "\n";
				par[v[e]] = e;
				dist[v[e]] = dist[n] + c[e];
				if(!inqu[v[e]]){
					inqu[v[e]] = 1;
					qu.push(v[e]);
				}
			}
		}
	}
	//cout << "ended\n";
	//exit(0);
	if(dist[2*N+1] >= 99999){
		return -1;
	}
	return dist[2*N+1];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i =1; i<=N; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	for(int i = 1; i<=N; i++){
		addedge(0, i, 2, 0);
		for(int j = 1; j<=N; j++){
			if(arr[i].second > arr[j].second){
				addedge(i, j+N, 1, 
				sqrt((arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)+(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second)));
			}
		}
		addedge(i+N, 2*N+1, 1, 0);
	}
	long double val;
	long double ans = 0;
	int flw = 0;
	while((val = spfa())>= 0){
		//cout << "it" << endl;
		ans += val;
		int n = 2*N+1;
		while(n){
			int e = par[n];
			//cout << e << " " << f[e] << endl;
			f[e]--;
			f[e^1]++;
			n = u[e];
		}
		flw++;
	}
	if(flw != N-1){
		cout << -1 << "\n";
	}
	else{
		cout << setprecision(12) << ans << "\n";
	}
}