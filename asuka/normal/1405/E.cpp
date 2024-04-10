#include<bits/stdc++.h>
#define ll long long
#define N 300015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
namespace Seg{
	#define ls(x) ch[x][0]
	#define rs(x) ch[x][1]
	int ch[N<<5][2],tot,val[N<<5],rt[N];
	void pushup(int x){
		val[x] = val[ls(x)]+val[rs(x)];
	}
	void build(int &x,int l,int r){
		if(!x) x = ++tot;
		if(l == r) return;
		int mid = (l+r)>>1;
		build(ls(x),l,mid);
		build(rs(x),mid+1,r);
	}
	void add(int &x,int pre,int l,int r,int pos,int num){
		if(!x) x = ++tot;
		if(l == r){
			val[x] = val[pre]+num;
			return;
		}
		int mid = (l+r)>>1;
		if(pos <= mid) ch[x][1] = ch[pre][1],add(ls(x),ls(pre),l,mid,pos,num);
		else ch[x][0] = ch[pre][0],add(rs(x),rs(pre),mid+1,r,pos,num);
		pushup(x);
	}
	int query(int p,int l,int r,int x,int y){
		if(x <= l && r <= y)
			return val[p];
		int mid = (l+r)>>1,res = 0;
		if(x <= mid) res += query(ls(p),l,mid,x,y);
		if(y > mid) res += query(rs(p),mid+1,r,x,y);
		return res;
	}
	int Binary(int x,int l,int r,int k){
		if(l==r) return l;
		int mid = (l+r)>>1;
		if(val[rs(x)] >= k) return Binary(rs(x),mid+1,r,k);
		else return Binary(ls(x),l,mid,k-val[rs(x)]);
	}
}
using namespace Seg;
int n,q,a[N],lim[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&q);
	build(rt[0],0,n-1);
	rep(i,1,n) scanf("%d",&a[i]),a[i] = i-a[i];
	rep(i,1,n){
		if(a[i] < 0||val[rt[i-1]] < a[i]){
			rt[i] = rt[i-1];
			lim[i] = -1;
			continue;
		}
		if(!a[i]) lim[i] = i-1;
		else lim[i] = Binary(rt[i-1],0,n-1,a[i]);
		add(rt[i],rt[i-1],0,n-1,lim[i],1);
	}
	rep(i,1,q){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n", query(rt[n-r],0,n-1,l,n-1));
	}
	return 0;
}