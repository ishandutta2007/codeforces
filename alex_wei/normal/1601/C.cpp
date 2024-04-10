#include <bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) begin(x),end(x)
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

char buf[1<<21],*p1=buf,*p2=buf;
#define gc getchar()
inline int read(){
    int x=0,sgn=0; char s=gc;
    while(!isdigit(s))sgn|=s=='-',s=gc;
    while(isdigit(s))x=x*10+s-'0',s=gc;
    return sgn?-x:x;
}

template <class T1,class T2> void cmin(T1 &a,T2 b){a=a<b?a:b;}
template <class T1,class T2> void cmax(T1 &a,T2 b){a=a>b?a:b;}

const int N=1e6+5;

ll n,m,a[N],b[N],c[N],d[N],e[N],id[N],ans;
struct BIT{
	int c[N];
	void add(int x){while(x<=n)c[x]++,x+=x&-x;}
	int query(int x){int s=0;while(x)s+=c[x],x-=x&-x;return s;}
}tr;
struct SegTree{
	int laz[N<<2],val[N<<2];
	void build(int l,int r,int x){
		if(l==r)return val[x]=d[l],void();
		int m=l+r>>1;
		build(l,m,x<<1),build(m+1,r,x<<1|1);
		val[x]=min(val[x<<1],val[x<<1|1]);
	}
	void push(int x){
		if(laz[x]){
			val[x<<1]+=laz[x],val[x<<1|1]+=laz[x];
			laz[x<<1]+=laz[x],laz[x<<1|1]+=laz[x],laz[x]=0; 
		}
	}
	void modify(int l,int r,int ql,int qr,int x,int v){
		if(ql<=l&&r<=qr)return val[x]+=v,laz[x]+=v,void();
		int m=l+r>>1; push(x);
		if(ql<=m)modify(l,m,ql,qr,x<<1,v);
		if(m<qr)modify(m+1,r,ql,qr,x<<1|1,v);
		val[x]=min(val[x<<1],val[x<<1|1]);
	}
}tr2;
void solve(){
	n=read(),m=read(),mem(tr.c,0,n+5),d[0]=e[n+1]=0;
	mem(tr2.laz,0,n+5<<2),mem(tr2.val,0,n+5<<2),ans=0;
	for(int i=1;i<=n;i++)a[i]=read(),c[i]=a[i],id[i]=i;
	for(int i=1;i<=m;i++)b[i]=read();
	sort(c+1,c+n+1),sort(b+1,b+m+1);
	sort(id+1,id+n+1,[](int x,int y){return a[x]<a[y];});
	for(int i=1;i<=n;i++)a[i]=lower_bound(c+1,c+n+1,a[i])-c;
	for(int i=1;i<=n;i++)ans+=i-1-tr.query(a[i]),tr.add(a[i]);
	for(int i=1;i<=n;i++)a[i]=c[a[i]];
	for(int i=1;i<=n;i++)d[i]=d[i-1]+(a[i]>b[1]);
	for(int i=n;i;i--)e[i]=e[i+1]+(a[i]<b[1]),d[i-1]+=e[i];
	tr2.build(0,n,1); int p1=1,p2=1;
	while(p1<=n&&a[id[p1]]<=b[1])p1++;
	while(p2<=n&&a[id[p2]]<b[1])p2++;
	for(int i=1;i<m;i++){
		ans+=tr2.val[1];
		while(p1<=n&&a[id[p1]]<=b[i+1])tr2.modify(0,n,id[p1],n,1,-1),p1++;
		while(p2<=n&&a[id[p2]]<b[i+1])tr2.modify(0,n,0,id[p2]-1,1,1),p2++;
	}
	cout<<ans+tr2.val[1]<<endl;
}
int main(){
	int T; cin>>T;
	while(T--)solve();
    return 0;
}