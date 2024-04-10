#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n, m;
int deg[200200];
vector<int> rev[200200];
ll dist[200200];
ll val[200200];

int main(){
	ios::sync_with_stdio(false); 
	cin >> n >> m;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		deg[a]++;
		rev[b].push_back(a);
	}
	rep(i, n)
		dist[i] = 0x3f3f3f3f3f3f3f3fll, val[i] = deg[i] - 1;
	dist[n - 1] = 0;
	priority_queue< pair<ll, int> > pq;
	pq.push(make_pair(0, n - 1));
	while(!pq.empty()){
		int nowpos = pq.top().second;
		ll nowval = -pq.top().first;
		pq.pop();
		if(nowval != dist[nowpos])
			continue;
		rep(i, (int)rev[nowpos].size()){
			if(val[rev[nowpos][i]] + nowval + 1 < dist[rev[nowpos][i]]){
				dist[rev[nowpos][i]] = val[rev[nowpos][i]] + nowval + 1;
				pq.push(make_pair(-dist[rev[nowpos][i]], rev[nowpos][i]));
			}
			val[rev[nowpos][i]]--;
		}
	}
	cout << dist[0] << endl;
	return 0;
}