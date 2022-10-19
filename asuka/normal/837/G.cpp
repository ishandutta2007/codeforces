#include<bits/stdc++.h>
#define int long long
#define N 75015
#define M 200015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,q,m,l[N],r[N],a[N],b[N],y1[N],y2[N],t1[N],t2[N];
struct Tree{
	int sum[M<<5],ls[M<<5],rs[M<<5],rt[N],tot;
	inline void init(int &p,int l,int r){
		if(!p) p = ++tot;
		if(l == r) return;
		int mid = (l+r)>>1;
		init(ls[p],l,mid); init(rs[p],mid+1,r);
	}
	inline void add(int pre,int &p,int l,int r,int pos,int val){
		p = ++tot;
		sum[p] = sum[pre]+val;
		if(l == r) return;
		int mid = (l+r)>>1;
		if(pos <= mid) rs[p] = rs[pre],add(ls[pre],ls[p],l,mid,pos,val);
		else ls[p] = ls[pre],add(rs[pre],rs[p],mid+1,r,pos,val);
	}
	inline int query(int p,int l,int r,int x,int y){
		if(l > r) return 0;
		if(x <= l && r <= y) return sum[p];
		int res = 0,mid = (l+r)>>1;
		if(x <= mid) res += query(ls[p],l,mid,x,y);
		if(y > mid) res += query(rs[p],mid+1,r,x,y);
		return res;
	}
}A,B;
int solve(int pos,int x){
	if(pos == 0) return 0;
	return A.query(A.rt[pos],0,m,0,min(x,m))*x + B.query(B.rt[pos],0,m,0,min(x,m));
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&n);
 	rep(i,1,n) scanf("%lld%lld%lld%lld%lld%lld",&l[i],&r[i],&y1[i],&a[i],&b[i],&y2[i]);

 	rep(i,1,n) m = max(m,r[i]+2);
 	A.init(A.rt[0],0,m); B.init(B.rt[0],0,m);
 	rep(i,1,n){
 		A.add(A.rt[i-1],A.rt[i],0,m,l[i]+1,a[i]);
 		A.add(A.rt[i],A.rt[i],0,m,r[i]+1,-a[i]);
 	}
 	rep(i,1,n){
 		B.add(B.rt[i-1],B.rt[i],0,m,0,y1[i]);
 		B.add(B.rt[i],B.rt[i],0,m,l[i]+1,b[i] - y1[i]);
 		B.add(B.rt[i],B.rt[i],0,m,r[i]+1,y2[i] - b[i]);
 	}
 	int las = 0;
 	scanf("%lld",&q);
 	rep(i,1,q){
 		int L,R,x;
 		scanf("%lld%lld%lld",&L,&R,&x); x = (x + las) % 1000000000;
 		printf("%lld\n",las = solve(R,x) - solve(L-1,x));
 	}
	return 0;
}
/*
4
4 6 8 3 2 8
4 9 9 5 8 3
0 10 6 9 4 7
1 6 5 3 0 2
1
1 4 6

134

7
4 8 562244866 6 8 140807945
5 7 415374420 7 6 596093578
3 4 766370993 3 7 973128805
4 6 841321398 3 2 893107667
4 9 968214628 5 8 329310838
0 10 64315145 9 4 716996081
1 6 568407659 3 0 22184171
1
4 7 647898558
*/