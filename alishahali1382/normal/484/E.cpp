#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

struct node{
	int ans, pref, suff, full;
	node(int x=0){ ans=pref=suff=full=x;}
	//bool operator <(node x){ return 0;}
};

node combine(node x, node y){
	node out;
	out.ans=max(max(x.ans, y.ans), x.suff+y.pref);
	out.pref=x.pref;
	out.suff=y.suff;
	out.full=x.full&y.full;
	if (x.full) out.pref=x.pref+y.pref;
	if (y.full) out.suff=y.suff+x.suff;
	return out;
}

int n, m, k, u, v, x, y, t, l, r, w, rcnt, N;
int A[MAXN];
int L[MAXN*LOG];
int R[MAXN*LOG];
node seg[MAXN*LOG];
pii root[MAXN];
map<int, vector<int>> mp;

int build(int tl, int tr){
	if (tr-tl==1){
		seg[++N]=node(0);
		return N;
	}
	int mid=(tl+tr)>>1;
	int id=++N;
	L[id]=build(tl, mid);
	R[id]=build(mid, tr);
	seg[id]=combine(seg[L[id]], seg[R[id]]);
	return id;
}

int update(int id, int tl, int tr, int pos){
	if (pos<tl || tr<=pos) return id;
	int ID=++N;
	if (tr-tl==1){
		seg[ID]=node(1);
		return ID;
	}
	int mid=(tl+tr)>>1;
	L[ID]=update(L[id], tl, mid, pos);
	R[ID]=update(R[id], mid, tr, pos);
	seg[ID]=combine(seg[L[ID]], seg[R[ID]]);
	return ID;
}

node get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return node(0);
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return combine(get(L[id], tl, mid, l, r), get(R[id], mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], mp[-A[i]].pb(i);
	root[rcnt++]={inf, build(1, n+1)};
	
	for (auto it:mp){
		int tmp=root[rcnt-1].second;
		for (int i:it.second) tmp=update(tmp, 1, n+1, i);
		root[rcnt++]={-it.first, tmp};
	}
	reverse(root, root+rcnt);
	
	cin>>m;
	while (m--){
		cin>>l>>r>>w;
		int dwn=0, up=inf;
		while (up-dwn>1){
			int mid=(dwn+up)>>1;
			int tmp=lower_bound(root, root+rcnt, pii(mid, 0))->second;
			if (get(tmp, 1, n+1, l, r+1).ans>=w) dwn=mid;
			else up=mid;
		}
		cout<<dwn<<'\n';
	}
	
	
	return 0;
}
/*
4
2 2 3 3
1
1 4 2

*/