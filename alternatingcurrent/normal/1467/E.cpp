#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
int a[200200];
int cnt[200200];
set<int> st;
map<int, int> mp;
vector< pair<int, bool> > col[200200];
vector<int> v[200200];
int all = 0;
int fa[200200];
int tag[200200];
int laz[800800];
int dat[800800];
int gval[800800];
int nl[200200], nr[200200];
int ncnt = 0;
void dfs1(int now, int par){
	fa[now] = par;
	nl[now] = ncnt++;
	rep(i, (int)v[now].size()) if(v[now][i] != par) dfs1(v[now][i], now);
	nr[now] = ncnt;
}
void pushdown(int k, int l, int r){
	int mid = (l + r) >> 1;
	if(gval[k] >= 0){
		gval[k+k] = gval[k], gval[k+k+1] = gval[k];
		laz[k+k] = 0, laz[k+k+1] = 0;
		dat[k+k] = gval[k] * (mid - l + 1), dat[k+k+1] = gval[k] * (r - mid);
		gval[k] = -1;
		return ; 
	}
	laz[k+k] += laz[k], dat[k+k] += laz[k] * (mid - l + 1);
	laz[k+k+1] += laz[k], dat[k+k+1] += laz[k] * (r - mid);
	laz[k] = 0;
}
void update(int tl, int tr, int val, int l, int r, int k){
	if(l != r) pushdown(k, l, r);
	if(tl > r || l > tr) return ;
	if(tl <= l && r <= tr){
		laz[k] += val, dat[k] += val * (r - l + 1);
		return ;
	}
	int mid = (l + r) >> 1;
	update(tl, tr, val, l, mid, k+k);
	update(tl, tr, val, mid+1, r, k+k+1);
	dat[k] = dat[k+k] + dat[k+k+1];
}
int query(int tl, int tr, int l, int r, int k){
	if(l != r) pushdown(k, l, r);
	if(tl > r || l > tr) return 0;
	if(tl <= l && r <= tr){
		return dat[k];
	}
	int mid = (l + r) >> 1;
	return query(tl, tr, l, mid, k+k) + query(tl, tr, mid+1, r, k+k+1);
}

void dfs2(int now, int par){
	rep(i, (int)v[now].size()){
		if(v[now][i] != par){
			tag[v[now][i]] += tag[now];
			dfs2(v[now][i], now);
		}
	}
	tag[now] += all;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n-1){
		int x, y;
		cin >> x >> y;
		x--, y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(0, -1);
	rep(i, n) st.insert(a[i]);
	int colcnt = 0;
	for(set<int>::iterator it = st.begin(); it != st.end(); it++, colcnt++) mp[*it] = colcnt;
	rep(i, n) a[i] = mp[a[i]];
	rep(i, n) cnt[a[i]]++;
	rep(i, n) col[a[i]].push_back(make_pair(i, 0));
	for(int i = 1; i < n; i++) col[a[fa[i]]].push_back(make_pair(i, 1));
	memset(gval, -1, sizeof(gval));
	rep(i, colcnt){
		gval[1] = 0;
		dat[1] = 0, laz[1] = 0;
		rep(j, (int)col[i].size()){
			if(col[i][j].second) break;
			update(nl[col[i][j].first], nl[col[i][j].first], 1, 0, n-1, 1);
		} 
		rep(j, (int)col[i].size()){
			int in = query(nl[col[i][j].first], nr[col[i][j].first] - 1, 0, n-1, 1);
			in -= (col[i][j].second ^ 1);
			if(col[i][j].second) {
				if(in > 0) all++, tag[col[i][j].first]--;
			} else{
				if(cnt[i] - in - 1 > 0) tag[col[i][j].first]++;
			} 
		}
	}
	dfs2(0, -1);
	int ans = 0;
	rep(i, n) ans += (bool)(tag[i] == 0);
	cout << ans << endl;
	return 0;
}