#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll qmin(ll a, ll b){
	return (a < b) ? a : b;
}

int n, m;
int par[777];
ll dist[777][777];
vector< pair<int, ll> > v[200200];
pair< ll, pair<int, int> > e[200200];
int getpar(int now){
	return par[now] = ((par[now] == now) ? now : getpar(par[now]));
}

int cnt_edge[200200];
priority_queue< pair<ll, int> > ne;
bool in[200200];
int tot = 0;
queue<int> q;

ll solve_700(){
	q.push(0);
	in[0] = 1;
	ll ans = 0;
	while(tot < n){
		while(!q.empty()){
			int now = q.front(); q.pop();
			rep(i, (int)v[now].size()){
				cnt_edge[v[now][i].first]++;
				ne.push(make_pair(-v[now][i].second, v[now][i].first));
			}
			tot++;
		}
		rep(i, n) if(!in[i] && cnt_edge[i] < tot) q.push(i), in[i] = 1;
		if(q.empty()){
			while(!ne.empty()){
				int now = ne.top().second;
				ll nowval = -ne.top().first;
				ne.pop();
				if(in[now]) continue;
				ans += nowval;
				in[now] = 1;
				q.push(now);
				break;
			}
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m){
		int a, b; ll c;
		cin >> a >> b >> c;
		a--, b--;
		e[i] = make_pair(c, make_pair(a, b));
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	if(n > 700){
		cout << solve_700() << endl;
	} else {
		memset(dist, 0x3f, sizeof(dist));
		ll val = 0;
		rep(i, m){
			int a = e[i].second.first, b = e[i].second.second;
			ll c = e[i].first;
			val ^= c;
			dist[a][b] = qmin(c, dist[a][b]);
			dist[b][a] = qmin(c, dist[b][a]);
		}
		e[m] = (make_pair(val, make_pair(-1, -1)));
		sort(e, e + m + 1);
		rep(i, n) par[i] = i;
		ll INF = 0x3f3f3f3f3f3f3f3f;
		bool found_ok = 0;
		vector< pair<int, int> > edge0;
		rep(i, n){
			rep(j, i){
				if(i == j || dist[i][j] < INF) continue;
				if(getpar(i) == getpar(j)) found_ok = 1;
				par[getpar(i)] = getpar(j);
				edge0.push_back(make_pair(i, j));
			}
		}
		if(found_ok){
			ll ans = 0;
			rep(i, m + 1){
				if(e[i].second == make_pair(-1, -1)) continue;
				if(getpar(e[i].second.first) != getpar(e[i].second.second)){
					ans += e[i].first;
					par[getpar(e[i].second.first)] = getpar(e[i].second.second);
				}
			}
			cout << ans << endl;
		} else {
			ll res = 0x3f3f3f3f3f3f3f3f;
			rep(e1, (int)edge0.size()){
				rep(k, n) par[k] = k;
				rep(e2, (int)edge0.size()) if(e1 != e2 && getpar(edge0[e2].first) != getpar(edge0[e2].second)) par[getpar(edge0[e2].first)] = getpar(edge0[e2].second);
				ll ans = 0;
				rep(ei, m + 1){
					if(e[ei].second == make_pair(-1, -1)) e[ei].second = edge0[e1];
					if(getpar(e[ei].second.first) != getpar(e[ei].second.second)){
						ans += e[ei].first;
						par[getpar(e[ei].second.first)] = getpar(e[ei].second.second);
					}
				}
				res = qmin(res, ans);
			}
			cout << res << endl;
		}
	}
	return 0;
}