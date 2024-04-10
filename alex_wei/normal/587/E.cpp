#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long
#define pb emplace_back
#define pii pair <int,int>
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))
//
#define gc getchar()
inline ll read(){
	ll x=0,sgn=0; char s=gc;
	while(!isdigit(s))sgn|=s=='-',s=gc;
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=gc;
	return sgn?-x:x;
}

const int N=2e5+5;
const int L=30;
const int mod=1e9+7;

int n,q,a[N],b[N];
struct BIT{
	int c[N];
	void add(int x,int v){while(x<=n)c[x]^=v,x+=x&-x;}
	void add(int l,int r,int v){add(l,v),add(r+1,v);}
	int query(int x){int s=0; while(x)s^=c[x],x-=x&-x; return s;}
}tr;

struct LB{
	int a[L],size;
	void clear(){mem(a,0,L),size=0;}
	void insert(int x){
		if(!x)return;
		for(int i=L-1;~i;i--)
			if(x>>i&1){
				if(a[i]){x^=a[i]; continue;}
				for(int j=i-1;~j;j--)if(x>>j&1)x^=a[j];
				for(int j=i+1;j<L;j++)if(a[j]>>i&1)a[j]^=x;
				return a[i]=x,size++,void();
			}
	}
	void insert(LB &x){
		for(int i=0;i<L;i++)insert(x.a[i]);
	}
}val[N<<2],ans;

void modify(int l,int r,int x,int p,int v){
	if(l==r)return val[x].clear(),val[x].insert(b[l]^=v),void();
	int m=l+r>>1;
	if(p<=m)modify(l,m,x<<1,p,v);
	else modify(m+1,r,x<<1|1,p,v);
	val[x]=val[x<<1],val[x].insert(val[x<<1|1]);
}
void query(int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr)return ans.insert(val[x]),void();
	int m=l+r>>1;
	if(ql<=m)query(l,m,ql,qr,x<<1);
	if(m<qr)query(m+1,r,ql,qr,x<<1|1);
}

int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i],tr.add(i,a[i]),tr.add(i+1,a[i]);
		modify(1,n,1,i,a[i]^a[i-1]);
	}
	for(int i=1;i<=q;i++){
		int op,l,r,x; cin>>op>>l>>r;
		if(op==1){
			cin>>x,tr.add(l,r,x),modify(1,n,1,l,x);
			if(r<n)modify(1,n,1,r+1,x);
		} else{
			ans.clear(),ans.insert(tr.query(l));
			if(l<r)query(1,n,l+1,r,1); cout<<(1<<ans.size)<<endl;
		}
	}
	return 0;
}