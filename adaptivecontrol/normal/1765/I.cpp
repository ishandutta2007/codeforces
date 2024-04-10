#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int xs, ys, xt, yt;

int n;
int x[2020], y[2020];
char tp[2020];

int cc = 0;
vector<int> mark;
bool occ[40040][9], ban[40040][9];
int cn = 0, id[40040][9];
vector< pair<int, ll> > g[400400];
void ae(int a, int b, ll v){
//	cout << "ae " << a << " " << b << " " << v << endl;
	g[a].emplace_back(b, v);
	g[b].emplace_back(a, v);
}

ll dis[400400];
ll dijkstra(int S, int T){
	memset(dis, 0x3f, sizeof(dis));
	dis[S] = 0;
	priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > pq;
	pq.emplace(0, S);
	while(!pq.empty()){
		int np = pq.top().second; ll nd = pq.top().first; pq.pop();
		rep(i, (int)g[np].size()){
			int t = g[np][i].first; ll w = g[np][i].second;
			if(nd + w < dis[t]){
				dis[t] = nd + w;
				pq.emplace(dis[t], t);
			}
		}
	}
	return dis[T];
}

int main(){
	ios::sync_with_stdio(false);
	
	cin >> xs >> ys >> xt >> yt;
	--ys, --yt;
	mark.push_back(xs), mark.push_back(xt);
	
	cin >> n;
	rep(i, n){
		cin >> tp[i] >> x[i] >> y[i];
		--y[i];
		
		int d = 8;
		if(tp[i] == 'K' || tp[i] == 'R')
			d = 2;
		else if(tp[i] == 'N')
			d = 3;
		for(int j = x[i]-d; j <= x[i]+d; ++j)
			mark.push_back(j);
	}
	
	sort(mark.begin(), mark.end());
	mark.resize(unique(mark.begin(), mark.end()) - mark.begin());
	cc = (int)mark.size();
	
	rep(i, n){
		int nx = (int)(lower_bound(mark.begin(), mark.end(), x[i]) - mark.begin());
		occ[nx][y[i]] = ban[nx][y[i]] = 1;
	}
	
//	rep(i, cc){
//		cout << i << " " << mark[i] << ": ";
//		rep(j, 8)
//			cout << occ[i][j] << " ";
//		cout << endl;
//	}
	
	rep(i, n){
		int nx = (int)(lower_bound(mark.begin(), mark.end(), x[i]) - mark.begin());
//		cout << nx << endl;
		if(tp[i] == 'N'){
			if(y[i] >= 1)
				ban[nx-2][y[i]-1] = ban[nx+2][y[i]-1] = 1;
			if(y[i] >= 2)
				ban[nx-1][y[i]-2] = ban[nx+1][y[i]-2] = 1;
			if(y[i] <= 5)
				ban[nx-1][y[i]+2] = ban[nx+1][y[i]+2] = 1;
			if(y[i] <= 6)
				ban[nx-2][y[i]+1] = ban[nx+2][y[i]+1] = 1;
		} else if(tp[i] == 'K'){
			if(y[i] >= 1)
				ban[nx-1][y[i]-1] = ban[nx][y[i]-1] = ban[nx+1][y[i]-1] = 1;
			ban[nx-1][y[i]] = ban[nx][y[i]] = ban[nx+1][y[i]] = 1;
			if(y[i] <= 6)
				ban[nx-1][y[i]+1] = ban[nx][y[i]+1] = ban[nx+1][y[i]+1] = 1;
		} else {
			if(tp[i] == 'Q' || tp[i] == 'B'){
				for(int d = 1; y[i]-d >= 0; ++d){
//					cout << d << endl;
					if(occ[nx-d][y[i]-d]) break;
					ban[nx-d][y[i]-d] = 1;
				}
				for(int d = 1; y[i]-d >= 0; ++d){
//					cout << d << endl;
					if(occ[nx+d][y[i]-d]) break;
					ban[nx+d][y[i]-d] = 1;
				}
				for(int d = 1; y[i]+d < 8; ++d){
//					cout << d << endl;
					if(occ[nx-d][y[i]+d]) break;
					ban[nx-d][y[i]+d] = 1;
				}
				for(int d = 1; y[i]+d < 8; ++d){
//					cout << d << endl;
					if(occ[nx+d][y[i]+d]) break;
					ban[nx+d][y[i]+d] = 1;
				}
			}
			
			if(tp[i] == 'Q' || tp[i] == 'R'){
				for(int d = 1; y[i]-d >= 0; ++d){
//					cout << "skfda " << d << endl;
					if(occ[nx][y[i]-d]) break;
					ban[nx][y[i]-d] = 1;
				}
				for(int d = 1; y[i]+d < 8; ++d){
//					cout << "skfda " << d << endl;
					if(occ[nx][y[i]+d]) break;
					ban[nx][y[i]+d] = 1;
				}
				for(int d = 1; nx-d >= 0; ++d){
//					cout << "skfda " << d << endl;
					if(occ[nx-d][y[i]]) break;
					ban[nx-d][y[i]] = 1;
				}
				for(int d = 1; nx+d < cc; ++d){
//					cout << "skfda " << d << endl;
					if(occ[nx+d][y[i]]) break;
					ban[nx+d][y[i]] = 1;
				}
			}
		}
	}
	
//	rep(i, cc){
//		cout << i << " " << mark[i] << ": ";
//		rep(j, 8)
//			cout << ban[i][j] << " ";
//		cout << endl;
//	}
	
//	cout << "mid" << endl;
	
	rep(i, cc) rep(j, 8){
//		cout << i << " " << j << endl; 
		if(!ban[i][j])
			id[i][j] = cn++;
	}
	
	rep(i, cc)
		rep(j, 7)
			if(!ban[i][j] && !ban[i][j+1])
				ae(id[i][j], id[i][j+1], 1);
	
	rep(i, cc-1){
		if(mark[i+1] == mark[i]+1){
			rep(j, 8){
				if(!ban[i][j] && !ban[i+1][j])
					ae(id[i][j], id[i+1][j], 1);
				if(j < 7 && !ban[i][j] && !ban[i+1][j+1])
					ae(id[i][j], id[i+1][j+1], 1);
				if(j > 0 && !ban[i][j] && !ban[i+1][j-1])
					ae(id[i][j], id[i+1][j-1], 1);
			}
		} else {
			int d = mark[i+1] - mark[i];
			rep(j, 8){
				if(ban[i][j]) continue;
				for(int k = j; k < 8; ++k){
					if(ban[i][k]) break;
					ae(id[i][j], id[i+1][k], max(d, k-j));
				}
				for(int k = j-1; k >= 0; --k){
					if(ban[i][k]) break;
					ae(id[i][j], id[i+1][k], max(d, j-k));
				}
			}
		}
	}
	
	xs = (int)(lower_bound(mark.begin(), mark.end(), xs) - mark.begin());
	xt = (int)(lower_bound(mark.begin(), mark.end(), xt) - mark.begin());
	ll ret = dijkstra(id[xs][ys], id[xt][yt]);
	if(ret >= 0x3f3f3f3f3f3f3f3fll)
		cout << "-1\n";
	else
		cout << ret << "\n";
	
	return 0;
}