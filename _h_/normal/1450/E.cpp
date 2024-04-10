#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int inf = 1e9;

void fail(){
	cout << "NO" << endl;
	exit(0);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	vi is(m), js(m), bs(m);
	rep(i,0,m) cin >> is[i] >> js[i] >> bs[i];
	trav(x, is) --x;
	trav(x, js) --x;

	vector<vi> dist(n, vi(n, inf));
	rep(t,0,m){
		int i = is[t], j = js[t], b = bs[t];
		if(b){
			dist[i][j] = 1;
			dist[j][i] = -1;
		} else {
			dist[i][j] = 1;
			dist[j][i] = 1;
		}
	}
	rep(i,0,n) dist[i][i] = 0;
	rep(k,0,n) rep(i,0,n) rep(j,0,n){
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		if(dist[i][j] < -inf) fail();
	}
	rep(i,0,n) if(dist[i][i] < 0) fail();	
	rep(t,0,m) if( abs(dist[0][is[t]] - dist[0][js[t]]) % 2 == 0 ) fail();
	int i0 = 0, j0 = 0;
	rep(i,0,n) rep(j,0,n) if(dist[i][j] > dist[i0][j0]){
		i0 = i;
		j0 = j;
	}
	cout << "YES" << endl;
	cout << dist[i0][j0] << endl;
	rep(i,0,n) cout << dist[i0][i] << " ";
	cout << endl;
}