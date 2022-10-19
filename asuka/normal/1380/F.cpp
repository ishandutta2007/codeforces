#include<bits/stdc++.h>
#define ll long long
#define N 500015
#define mod 998244353
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
int n,m,g1[N],g2[N];
int s[N];
int get(int x){
	int cnt = 0;
	rep(i,0,9) rep(j,0,9){
		if(i+j == x) cnt++;
	}
	return cnt;
}
struct matrix{
	#define len 2
	ll a[3][3];
	matrix(){memset(a,0,sizeof a);}
	ll* operator [](int i){return a[i];}
	matrix operator *(matrix lhs) const{
		matrix tmp;
		rep(i,1,len) rep(j,1,len) rep(k,1,len){
			(tmp[i][k] += a[i][j]*lhs[j][k])%=mod;
		}
		return tmp;
	}
}base;
matrix Get(int i){
	matrix u;
	u[1][1] = g1[s[i]];
	u[1][2] = (s[i]==1&&i>1)?g2[s[i-1]]:0;
	u[2][1] = 1;
	return u;
}
namespace seg{
	#define ls (p<<1)
	#define rs (p<<1|1)
	matrix t[N<<2];
	void pushup(int p){
		t[p] = t[rs] * t[ls];
	}
	void build(int p,int l,int r){
		if(l == r) return t[p] = Get(l),void();
		int mid = (l+r)>>1;
		build(ls,l,mid); build(rs,mid+1,r);
		pushup(p);
	}
	void change(int p,int l,int r,int pos){
		if(l == r) return t[p] = Get(pos),void();
		int mid = (l+r)>>1;
		if(pos <= mid) change(ls,l,mid,pos);
		else change(rs,mid+1,r,pos);
		pushup(p);
	}
	matrix query(){
		return t[1];
	}
}
using namespace seg;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,0,9) g1[i] = get(i);
	rep(i,0,9) g2[i] = get(10+i);
	rep(i,1,n) scanf("%1d",&s[n-i+1]);
	build(1,1,n);
	while(m--){
		int pos,val;
		scanf("%d%d",&pos,&val);
		pos = n-pos+1;
		base[1][1] = 1;
		s[pos] = val;
		change(1,1,n,pos);
		if(pos+1<=n) change(1,1,n,pos+1);
		// matrix nnn = t[1];
		// rep(i,1,2){
		// 	rep(j,1,2){
		// 		printf("%d ",nnn[i][j]);
		// 	}
		// 	printf("\n");
		// }
		base = base*query();
		printf("%lld\n",base[1][1]);
	}
	return 0;
}