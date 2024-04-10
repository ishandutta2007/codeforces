#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;

const int MAXN = 150010;

int n, len, h, ans;
int A[MAXN];
int B[MAXN];
int match[MAXN];
int seg[MAXN<<2];
int lazy[MAXN<<2];

void shift(int id){
	seg[id<<1]+=lazy[id];
	seg[id<<1 | 1]+=lazy[id];
	lazy[id<<1]+=lazy[id];
	lazy[id<<1 | 1]+=lazy[id];
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (r<tl || tr<l) return ;
	if (l<=tl && tr<=r){
		seg[id]+=val;
		lazy[id]+=val;
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid+1, tr, l, r, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>len>>h;
	for (int i=1; i<=len; i++) cin>>B[i], B[i]=h-B[i];
	B[0]=-2e9;
	sort(B+1, B+len+1);
	for (int i=1; i<=len; i++) update(1, 1, len, i, i, i-len-1);
	
	for (int i=1; i<=n; i++){
		cin>>A[i];
		match[i]=upper_bound(B, B+len+1, A[i])-B-1;
		update(1, 1, len, 1, match[i], 1);
		if (i<len) continue ;
		update(1, 1, len, 1, match[i-len], -1);
		ans+=(seg[1]>=0);
	}
	cout<<ans<<'\n';
	
	return 0;
}