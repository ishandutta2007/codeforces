#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define M 12000015
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
int n,k,q;
int a[N];
namespace RMQ{
	int Min[N][21],Log[N];
	void build(){
		rep(i,2,n) Log[i] = Log[i>>1] + 1;
		memset(Min,0x3f,sizeof Min);
		rep(i,1,n) Min[i][0] = a[i];
		rep(j,1,19){
			rep(i,1,n){
				if(i+(1<<j)-1 > n) break;
				Min[i][j] = min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int query(int l,int r){
		int k = Log[r-l+1];
		return min(Min[l][k],Min[r - (1<<k) + 1][k]);
	}
}
int ls[M],rs[M],mn[M],lazy[M],tot = 1,root = 1;
int query(int l,int r){
	if(r - l + 1 >= n) return RMQ::query(1,n);
	l -= ((l-1)/n)*n; r -= ((r-1)/n)*n;
	if(l <= r) return RMQ::query(l,r);
	return min(RMQ::query(1,r),RMQ::query(l,n));
}
int getval(int &p,int l,int r){
	if(!p) p = ++tot;
	else return mn[p];
	return mn[p] = query(l,r);
}
void setval(int &p,int val){
	if(!p) p = ++tot;
	lazy[p] = mn[p] = val;
}
void pushup(int p,int l,int r){
	int mid = (l+r)>>1;
	mn[p] = min(getval(ls[p],l,mid),getval(rs[p],mid+1,r));
}
void pushdown(int p,int l,int r){
	int mid = (l+r)>>1;
	if(!lazy[p]){
		getval(ls[p],l,mid); getval(rs[p],mid+1,r);
		lazy[ls[p]] = lazy[rs[p]] = 0;
	}else if(~lazy[p]){
		// puts("why?");
		setval(ls[p],lazy[p]);
		setval(rs[p],lazy[p]);
	}
	lazy[p] = -1;
}
void change(int &p,int l,int r,int x,int y,int val){
	if(!p) p = ++tot;
	if(x <= l && r <= y){
		mn[p] = lazy[p] = val;
		// printf("C %d %d %d\n",l,r,lazy[p]);
		return;
	}
	pushdown(p,l,r);
	int mid = (l+r)>>1;
	if(x <= mid) change(ls[p],l,mid,x,y,val);
	if(y > mid) change(rs[p],mid+1,r,x,y,val);
	if(l != r) pushup(p,l,r);
	// printf("C %d %d %d\n",l,r,lazy[p]);
}
int query(int p,int l,int r,int x,int y){
	// printf("Q %d %d %d\n",l,r,mn[p]);
	if(x <= l && r <= y) return mn[p];
	pushdown(p,l,r);
	int mid = (l+r)>>1,res = inf;
	if(x <= mid) res = min(res,query(ls[p],l,mid,x,y));
	if(y > mid) res = min(res,query(rs[p],mid+1,r,x,y));
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&k);
 	rep(i,1,n) scanf("%d",&a[i]);
 	RMQ::build();
 	scanf("%d",&q);
 	mn[1] = query(1,n);
 	while(q--){
 		int opt,l,r;
 		scanf("%d%d%d",&opt,&l,&r);
 		if(opt == 1){
 			int x; scanf("%d",&x);
 			change(root,1,n*k,l,r,x);
 		}else printf("%d\n",query(1,1,n*k,l,r));
 	}
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
1 1 4 5 1 4 1 1 4 5  1  4  1  1  4  5  1  4
->
1 3 3 3 3 3 3 3 3 3  1  4  1  1  4  5  1  4
->
1 3 3 3 2 2 2 2 2 2  2  2  2  2  2  5  1  4
6 3
1 1 4 5 1 4
3
1 2 10 3
1 5 15 2
2 3 11
*/