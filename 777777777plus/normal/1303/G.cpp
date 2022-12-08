#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+1;

int n,cnt,head[N];
int rt,d[N],mx[N],size[N],tot,sum;
bool vis[N];
struct nd{
    int ne,to;
}e[N<<1];

void in(int x,int y){
    e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;
}

int getrt(int x,int f=-1){
    size[x]=1;mx[x]=0;
    for(int i=head[x];i;i=e[i].ne)
    if(e[i].to!=f&&!vis[e[i].to]){
        getrt(e[i].to,x);
        size[x]+=size[e[i].to];
        if(size[e[i].to]>mx[x])
        mx[x]=size[e[i].to];
    }
    if(sum-size[x]>mx[x])mx[x]=sum-size[x];
    if(mx[rt]>mx[x])rt=x;
}

int m;
int pos[N];

struct ST{
	int tot;
	int ls[N*2],rs[N*2];
	struct line{
		ll k,b;
		int id;
		line(ll _k=0,ll _b=0,int _id=0){
			k=_k;b=_b;id=_id;
		}
	}w[N*2];
	
	ll get(line a,ll x0){
		return a.k*x0+a.b;
	}
	
	double inter(line a,line b){
		return 1.*(a.b-b.b)/(b.k-a.k);
	}
	
	bool cmp(line a,line b,ll x){
		if(!a.id)return 1;
		if(get(a,x)==get(b,x))return a.id>b.id;
	 	return get(a,x)<get(b,x);
	}
	
	int build(int l,int r){
		int x=++tot;
		if(l==r)return x;
		int mid=l+r>>1;
		ls[x]=build(l,mid);
		rs[x]=build(mid+1,r);
		return x;
	}
	
	void push(int x,int l,int r,line a){
		if(!w[x].id)w[x]=a;
		if(cmp(w[x],a,pos[l]))swap(w[x],a);
		if(l==r||a.k==w[x].k)return;
		double p=inter(w[x],a);
		if(p<pos[l]||p>pos[r])return;
		int mid=l+r>>1;
		if(p<=pos[mid])push(ls[x],l,mid,w[x]),w[x]=a;
		else push(rs[x],mid+1,r,a);
		return;
	}
	
	void change(int x,int l,int r,int L,int R,line a){
		if(L<=l&&r<=R)return void(push(x,l,r,a));
		int mid=l+r>>1;
		if(L<=mid)change(ls[x],l,mid,L,R,a);
		if(R>mid)change(rs[x],mid+1,r,L,R,a);
		return;
	}
	
	line solve(int x,int l,int r,ll x0){
		if(l==r)return w[x];
		int mid=l+r>>1;
		line ret;
		if(x0<=pos[mid])ret=solve(ls[x],l,mid,x0);
		else ret=solve(rs[x],mid+1,r,x0);
		if(cmp(ret,w[x],x0))return w[x];
		return ret;
	}
	
	void init(){
		for(int i=1;i<=tot;++i){
			ls[i]=rs[i]=0;
			w[i]=0;
		}
		tot=0;
	}
}T;

ll a[N];
ll f[N],g[N],dep[N];
ll ans;

void dfs1(int x,int fa=-1){
    for(int i=head[x];i;i=e[i].ne)
    if(!vis[e[i].to]&&e[i].to!=fa){
    	int y=e[i].to;
    	g[y]=g[x]+a[y];
    	f[y]=f[x]+g[y];
    	dep[y]=dep[x]+1;
    	pos[++m]=g[y];
    	ans=max(ans,f[y]);
    	ans=max(ans,g[y]*(1+dep[y])-f[y]);
    	dfs1(y,x);
    }
}

void add(int x,int fa=-1){
    T.change(1,1,m,1,m,{dep[x],f[x]-a[rt]*dep[x],1});
    for(int i=head[x];i;i=e[i].ne)
    if(!vis[e[i].to]&&e[i].to!=fa){
    	int y=e[i].to;
    	add(y,x);
	}
}

void ask(int x,int fa=-1){
	ans=max(ans,-f[x]+g[x]*dep[x]+T.get(T.solve(1,1,m,g[x]),g[x]));
    for(int i=head[x];i;i=e[i].ne)
    if(!vis[e[i].to]&&e[i].to!=fa){
    	int y=e[i].to;
    	ask(y,x);
	}
}

void Solve(int x){
	m=0;
	f[x]=g[x]=a[x];
	dep[x]=1;
	dfs1(x);
	sort(pos+1,pos+m+1);
	static int q[N];
	q[0]=0;
    for(int i=head[x];i;i=e[i].ne)if(!vis[e[i].to])q[++q[0]]=e[i].to;
    if(q[0]<2)return;
	T.init();
	T.build(1,m);
    for(int i=1;i<=q[0];++i){
    	ask(q[i]);
    	add(q[i]);
    }
	T.init();
	T.build(1,m);
    for(int i=q[0];i>=1;--i){
    	ask(q[i]);
    	add(q[i]);
    }
}

int dfs(int x){
    vis[x]=1;
    Solve(x);
    for(int i=head[x];i;i=e[i].ne)
    if(!vis[e[i].to]){
        sum=size[e[i].to];rt=0;getrt(e[i].to,0);
        dfs(rt);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<n;++i){
        scanf("%d%d",&x,&y);
        in(x,y);
        in(y,x);
    }
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    mx[0]=0x3f3f3f3f;
    sum=n;rt=0;getrt(1,0);
    dfs(rt);
    printf("%lld\n",ans);
}