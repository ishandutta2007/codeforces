#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 10010;

ll n, m, k, u, v, x, y, t, h, c, typ;
ll dist[MAXN];

bool mark[MAXN];
vector<pll> G[MAXN];
priority_queue<pll, vector<pll>, greater<pll>> pq;
void djkasra(){
	for (int i=0; i<k; i++) pq.push({dist[i], i});
	while (!pq.empty()){
		ll v=pq.top().second;
		pq.pop();
		//if (mark[v]) continue ;
		//mark[v]=1;
		for (pll p:G[v]){
			ll u=p.first, w=p.second;
			if (dist[v]+w<dist[u]) pq.push({dist[u]=dist[v]+w, u});
		}
	}
}

ll A[MAXN*10];
ll C[MAXN*10];
bool rem[MAXN*10];
bool ok[MAXN*10];
set<pll> st;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dist, 63, sizeof(dist));
	cin>>h>>n>>m>>k;
	for (int i=1; i<=n; i++){
		cin>>A[i]>>C[i];
		if (A[i]%k==1){
			ok[i]=1;
			st.insert({-C[i], i});
		}
	}
	dist[1]=0;
	while (m--){
		cin>>typ;
		if (typ==3){
			t++;
			if (st.empty()){
				cout<<"0\n";
				continue ;
			}
			ll tmp=(*st.begin()).second;
			//st.erase(st.begin());
			st.erase({-C[tmp], tmp});
			rem[tmp]=1;
			cout<<C[tmp]<<'\n';
			C[tmp]=0;
		}
		else if (typ==1){
			cin>>x;
			for (int i=0; i<k; i++) G[i].pb({(i+x)%k, x});
			memset(mark, 0, sizeof(mark));
			djkasra();
			for (int i=1; i<=n; i++){
				if (ok[i]) continue ;
				if (A[i]>=dist[A[i]%k]){
					ok[i]=1;
					st.insert({-C[i], i});
				}
			}
		}
		else{
			cin>>x>>y;
			if (rem[x] || !y) continue ;
			if (st.count({-C[x], x})){
				st.erase({-C[x], x});
				st.insert({-C[x]+y, x});
			}
			C[x]-=y;
		}
	}
	
	return 0;
}