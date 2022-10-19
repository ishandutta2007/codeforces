#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int dx[4] = {1 , -1 , 0 , 0} , dy[4] = {0 , 0 , 1 , -1};
int n , x[MAXN] , y[MAXN] , ans[MAXN] , dist[MAXN];
vector<pii> points;

int Find(int x , int y){
	int ind = lower_bound(all(points) , pii(x , y)) - points.begin();
	if(ind == SZ(points) || points[ind] != pii(x , y))	return -1;
	return ind;
}

void BFS(){
	queue<int> Q;
	for(int i = 0 ; i < SZ(points) ; i++){
		if(dist[i] == 0){
			Q.push(i);
			ans[i] = i;
		}
	}
	while(!Q.empty()){
		int v = Q.front(); Q.pop();
		int x = points[v].X , y = points[v].Y;
		for(int i = 0 ; i < 4 ; i++){
			int nx = x + dx[i] , ny = y + dy[i];
			int u = Find(nx , ny);
			if(u == -1 || dist[u] != MOD)	continue;
			dist[u] = dist[v] + 1;
			ans[u] = ans[v];
			Q.push(u);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> x[i] >> y[i];
		points.push_back({x[i] , y[i]});
		for(int j = 0 ; j < 4 ; j++){
			int nx = x[i] + dx[j] , ny = y[i] + dy[j];
			points.push_back({nx , ny});
		}
	}
	sort(all(points));
	points.resize(unique(all(points)) - points.begin());
	for(int i = 0 ; i < n ; i++){
		dist[Find(x[i] , y[i])] = MOD;
	}
	BFS();
	for(int i = 0 ; i < n ; i++){
		int v = Find(x[i] , y[i]);
		cout << points[ans[v]].X << sep << points[ans[v]].Y << endl;
	}

    return 0;
}
/*

*/