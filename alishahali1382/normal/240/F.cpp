#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
const int MAXN = 100010;

struct node{
	int cnt[27];
	int len, lazy=0;
} seg[4*MAXN];

node combine(node x, node y){
	node out;
	for (int i=1; i<=26; i++) out.cnt[i]=x.cnt[i]+y.cnt[i];
	out.len=x.len+y.len;
	out.lazy=0;
	return out; 
}

int n, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN];
char ch;

void build(int id, int tl, int tr){
	if (tl==tr){
		seg[id].len=1;
		seg[id].cnt[A[tl]]=1;
		return ;
	}
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid+1, tr);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

void add_lazy(int id, int val){
	memset(seg[id].cnt, 0, sizeof(seg[id].cnt));
	seg[id].cnt[val]=seg[id].len;
	seg[id].lazy=val;
}

void shift(int id){
	if (!seg[id].lazy) return ;
	for (int i=0; i<2; i++) add_lazy(id<<1 | i, seg[id].lazy);
	seg[id].lazy=0;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (r<tl || tr<l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid+1, tr, l, r, val);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

node get(int id, int tl, int tr, int l, int r){
	if (r<tl || tr<l) return seg[4*MAXN-1];
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return combine(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid+1, tr, l, r));
}

void print(int id, int tl, int tr){
	if (tl==tr) for (int i=1; i<=26; i++) if (seg[id].cnt[i]){
		char ch='a'-1+i;
		cout<<ch;
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	print(id<<1, tl, mid);
	print(id<<1 | 1, mid+1, tr);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>ch, A[i]=ch-'a'+1;
	memset(seg, 0, sizeof(seg));
	build(1, 1, n);
	while (m--){
		cin>>l>>r;
		node tmp=get(1, 1, n, l, r);
		vector<int> vec;
		for (int i=1; i<=26; i++) if (tmp.cnt[i]&1) vec.push_back(i);
		if (vec.size()>1) continue ;
		if (vec.size()==1) update(1, 1, n, (l+r)>>1, (l+r)>>1, vec.back());
		for (int i=1; i<=26; i++) if (tmp.cnt[i]>=2){
			int t=tmp.cnt[i]>>1;
			update(1, 1, n, l, l+t-1, i);
			update(1, 1, n, r-t+1, r, i);
			l+=t;
			r-=t;
		}
	}
	print(1, 1, n);
	
	return 0;
}