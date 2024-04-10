#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define lowbit(x) (x&(-x))
#define pb push_back

const int MAXN = 200010;

int n, m, x, y, t, l, r;
int pos[MAXN];
int ans[MAXN];
int BIT[MAXN];
vector<int> vec[MAXN];
vector<pair<int, int>> query[MAXN];

void add(int id, int x){ for (; id<MAXN; id+=lowbit(id)) BIT[id]+=x;}
int get(int id){
	int res=0;
	for (; id; id-=lowbit(id)) res+=BIT[id];
	return res;
}

void upd(int l, int r){
	if (l>r) swap(l, r);
	vec[l].pb(r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>x, pos[x]=i;
	for (int i=1; i<=n; i++) for (int j=i; j<MAXN; j+=i) upd(pos[i], pos[j]);
	for (int i=1; i<=m; i++){
		cin>>l>>r;
		query[l].pb({r, i});
	}
	for (int i=n; i; i--){
		for (int x:vec[i]) add(x, 1);
		for (auto p:query[i]) ans[p.second]=get(p.first);
	}
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}