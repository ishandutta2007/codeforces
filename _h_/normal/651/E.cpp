#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef vector<pii> vp;
typedef long double ld;

vi t;

int find(int a){
	return t[a]<0?a:t[a]=find(t[a]);
}

void uni(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(t[a]<t[b]) swap(a,b);
	t[b] -= t[a] == t[b];
	t[a] = b;
}

int main(){
	cin.sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	t.resize(n*m,-1);
	vector<vi> aa(n,vi(m));
	rep(i,0,n) rep(j,0,m) cin >> aa[i][j];
	vector<vector<vp> > gt(n,vector<vp>(m));
	vector<vp> syn(n,vp(m));
	rep(r,0,n){
		vi ixs(m);
		rep(j,0,m) ixs[j] = j;
		sort(allof(ixs),[&](int a, int b){return aa[r][a]<aa[r][b];});
		for(int i = 0; i < m;){
			int j = i+1;
			while(j < m && aa[r][ixs[j]] == aa[r][ixs[i]]) ++j;
			rep(x,i+1,j) uni(r*m + ixs[i], r*m + ixs[x]);
			i = j;
		}
	}
	rep(r,0,m){
		vi ixs(n);
		rep(j,0,n) ixs[j] = j;
		sort(allof(ixs),[&](int a, int b){return aa[a][r]<aa[b][r];});
		for(int i = 0; i < n;){
			int j = i+1;
			while(j < n && aa[ixs[j]][r] == aa[ixs[i]][r]) ++j;
			rep(x,i+1,j) uni(ixs[i]*m + r, ixs[x]*m + r);
			i = j;
		}
	}
	rep(i,0,n) rep(j,0,m){
		int f = find(i*m+j);
		syn[i][j] = pii(f/m, f%m);
	}
	vector<vi> cc(n,vi(m));
	rep(r,0,n){
		vi ixs(m);
		rep(j,0,m) ixs[j] = j;
		sort(allof(ixs),[&](int a, int b){return aa[r][a]<aa[r][b];});
		for(int i = 0; i < m;){
			int j = i+1;
			while(j < m && aa[r][ixs[j]] == aa[r][ixs[i]]) ++j;
			if(j < m){
				pii p = syn[r][ixs[i]], q = syn[r][ixs[j]];
				gt[p.first][p.second].pb(q);
				++cc[q.first][q.second];
			}
			i = j;
		}
	}
	rep(r,0,m){
		vi ixs(n);
		rep(j,0,n) ixs[j] = j;
		sort(allof(ixs),[&](int a, int b){return aa[a][r]<aa[b][r];});
		for(int i = 0; i < n;){
			int j = i+1;
			while(j < n && aa[ixs[j]][r] == aa[ixs[i]][r]) ++j;
			if(j < n){
				pii p = syn[ixs[i]][r], q = syn[ixs[j]][r];
				gt[p.first][p.second].pb(q);
				++cc[q.first][q.second];
			}
			i = j;
		}
	}
	queue<pii> st;
	vector<vi> ans(n,vi(m));
	rep(i,0,n) rep(j,0,m) if(cc[i][j] == 0 && syn[i][j] == pii(i,j)){
		st.push(pii(i,j));
		ans[i][j] = 1;
	}
	while(!st.empty()){
		pii p = st.front();
		st.pop();
		int i = p.first, j = p.second;
		for(pii q : gt[i][j])
			if(--cc[q.first][q.second] == 0){
				ans[q.first][q.second] = 1 + ans[i][j];
				st.push(q);
			}
	}
/*
cout << n << ' ' << m << endl;
rep(i,0,n){
	rep(j,0,m) cout << aa[i][j] << ' ';
	cout << endl;
}
*/
	rep(i,0,n){
		rep(j,0,m){
			pii p = syn[i][j];
			cout << ans[p.first][p.second] << ' ';
		}
		cout << endl;
	}
}