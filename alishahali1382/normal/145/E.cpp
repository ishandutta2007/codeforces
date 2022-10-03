#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
const int MAXN = 1000010;

struct node{
	int lis47, lis74, c4, c7;
	void rev(){
		swap(lis47, lis74);
		swap(c4, c7);
	}
} seg[4*MAXN];

node combine(node x, node y){
	node out={max(x.lis47, y.lis47), max(x.lis74, y.lis74), x.c4+y.c4, x.c7+y.c7};
	out.lis47=max(out.lis47, max(x.c4+y.lis47, x.lis47+y.c7));
	out.lis74=max(out.lis74, max(x.lis74+y.c4, x.c7+y.lis74));
	return out;
}

int n, m, k, u, v, x, y, t, l, r;
bool lazy[4*MAXN];
string s;

node build(int id, int tl, int tr){
	if (tl==tr){
		if (s[tl]=='4') return seg[id]={1, 1, 1, 0};
		return seg[id]={1, 1, 0, 1};
	}
	int mid=(tl+tr)>>1;
	return seg[id]=combine(build(id<<1, tl, mid), build(id<<1 | 1, mid+1, tr));
}

void shift(int id){
	if (!lazy[id]) return ;
	lazy[id]=0;
	for (int i=0; i<2; i++){
		lazy[id<<1 | i]^=1;
		seg[id<<1 | i].rev();
	}
}

void update(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return ;
	if (l<=tl && tr<=r){
		lazy[id]^=1;
		seg[id].rev();
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r);
	update(id<<1 | 1, mid+1, tr, l, r);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	s="."+s;
	build(1, 1, n);
	while (m--){
		cin>>s;
		if (s=="count"){
			cout<<seg[1].lis47<<'\n';
			continue ;
		}
		cin>>l>>r;
		update(1, 1, n, l, r);
	}
	
	return 0;
}