#include<bits/stdc++.h>
#define int long long
#define N 500015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define pii pair<long long,long long>
#define fi first
#define se second
#define all(x) x.begin(),x.end()
using namespace std;
int n,a[N],id[N],ans[N];
struct node{
	int st,len;
};
vector<node> v;
namespace seg{
	#define ls (p<<1)
	#define rs (p<<1|1)
	int Max[N<<2];
	void pushup(int p){Max[p] = max(Max[ls],Max[rs]);}
	void build(int p,int l,int r){
		if(l == r){
			Max[p] = -1;
			return;
		}
		int mid = (l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(p);
	}
	void modify(int p,int l,int r,int pos,int val){
		if(l == r){
			Max[p] = max(Max[p],val);
			return;
		}
		int mid = (l+r)>>1;
		if(pos <= mid) modify(ls,l,mid,pos,val);
		else modify(rs,mid+1,r,pos,val);
		pushup(p);
	}
	int query(int p,int l,int r,int x,int y){
		if(x <= l && r <= y){
			return Max[p];
		}
		int res = -1;
		int mid = (l+r)>>1;
		if(x <= mid) res = max(res,query(ls,l,mid,x,y));
		if(y > mid) res = max(res,query(rs,mid+1,r,x,y));
		return res;
	}
	#undef ls
	#undef rs
}
using namespace seg;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&n);
	rep(i,1,n) scanf("%1lld",&a[i]);
	//v.pb(node{0,inf});
	rep(i,1,n){
		if(a[i] == 1){
			if(a[i-1] == 0) v.pb(node{i,1});
			else v[(int)v.size()-1].len++;
			id[i] = (int)v.size()-1;
		}
	}
	//S.insert(mp(v[0].len,v[0].st));
	//puts("fuck");
	build(1,1,n);
	//puts("fuck");
	rep(i,1,n){
		if(a[i] == 0){
			if(a[i-1] == 1) modify(1,1,n,v[id[i-1]].len,id[i-1]);
			ans[i] = ans[i-1];
		}else{
			int c = id[i],cst = v[c].st;
			int clen = i-v[c].st+1;
			int id = query(1,1,n,clen+1,n);
			if(id == -1){
				ans[i] = clen*(1+clen)/2 + (cst-1)*clen;
			}else{
				int t = v[id].st,tlen =  v[id].len;
				int ted = t+tlen-1;
				int	full = ((cst-1) - (ted-clen+1) + 1)*clen;
				//cout <<"i: " << i <<" ed: " << ted << endl;
				ans[i] = full + ans[ted];
			}
			//printf("i: %lld cst: %lld clen: %lld ted: %lld tlen: %lld\n",i,cst,clen,ted,tlen);
			//for(auto x:S) printf("%lld %lld\n",x.fi,x.se); 
		}
	}
	// rep(i,1,n) printf("%4lld",ans[i]);
	// puts("");
	// rep(i,1,n) printf("%4lld",a[i]);
	// puts("");
	int sum = 0;
	sum = accumulate(ans+1,ans+n+1,0ll);
	printf("%lld\n",sum);
	return 0;
}
/*
0 1 1 0 1 1  0  0  1  1  0  1111100111000011001001000011111100110000101110110100000101100110110011
0 2 5 5 7 11 11 11 11 19 19 14 25 39 54 70 70 70 21 39 85 85 85 85 85 28 53 53 53 32 32 32 35 35 35 35

100
0110110011011111001110000110010010000111111001100001011101101000001011001101100111011111100111101110

11
01101100110

43
0110110011011111001110000110010010000111111
*/