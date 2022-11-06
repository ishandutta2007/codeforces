#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	vector<vi> a(n, vi(m));
	trav(v, a) trav(x, v) cin >> x;
	trav(v, a) trav(x, v) --x;
	vi rm(n), cm(m);
	rep(i,0,n) rep(j,0,m){
		rm[i] = max(rm[i], a[i][j]);
		cm[j] = max(cm[j], a[i][j]);
	}

	vi rc(n*m);
	rep(i,0,n) rep(j,0,m){
		if(a[i][j] == rm[i]) rc[a[i][j]] += 1;
		if(a[i][j] == cm[j]) rc[a[i][j]] += 2;
	}

	int diag = count(all(rc), 3);

	int xlo = diag, ylo = diag, xhi = diag, yhi = diag;

	vector<vi> ans(n, vi(m));

	queue<pii> ls;

	rrep(t,0,n*m){
		int ix, jx;
		if(rc[t] == 0){
			pii p = ls.front(); ls.pop();
			ix = p.first, jx = p.second;
		} else if(rc[t] == 3){
			--xlo, --ylo;
			ix = xlo, jx = ylo;
			rep(y,ylo+1,yhi) ls.push({xlo, y});
			rep(x,xlo+1,xhi) ls.push({x, ylo});
		} else if(rc[t] == 1){
			++xhi;
			ix = xhi-1, jx = yhi-1;
			rrep(y, ylo, yhi-1) ls.push({xhi-1, y});
		} else {
			++yhi;
			ix = xhi-1, jx = yhi-1;
			rrep(x, xlo, xhi-1) ls.push({x, yhi-1});
		}
		/*
		cerr << xlo << " " << ylo << endl;
		cerr << xhi << " " << yhi << endl;
		cerr << rc[t] << " " << ix << " " << jx << " " << t+1 << endl;
		cerr << endl;*/
		ans[ix][jx] = t;
	}

	trav(v, ans){
		trav(x, v) cout << x+1 << ' ';
		cout << endl;
	}
}