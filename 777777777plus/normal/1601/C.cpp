#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+55;

int CC;
int n,m;
int a[N],b[N];

int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}

struct ST{
    int tot;
    int ls[N],rs[N];
    int mx[N],tag[N];

    void up(int x){
        mx[x]=max(mx[ls[x]],mx[rs[x]]);
    }

    void down(int x,int l,int r){
        if(!tag[x])return;
        int mid=l+r>>1;
        if(ls[x]){
            tag[ls[x]]+=tag[x];
            mx[ls[x]]+=tag[x];
        }
        if(rs[x]){
            tag[rs[x]]+=tag[x];
            mx[rs[x]]+=tag[x];
        }
        tag[x]=0;
    }

    int build(int l,int r){
        int x=++tot;
        if(l==r){
            mx[x]=-l;
            return x;
        }
        int mid=l+r>>1;
        ls[x]=build(l,mid);
        rs[x]=build(mid+1,r);
        up(x);
        return x;
    }

    void change(int x,int l,int r,int L,int R,ll d){
        if(L<=l&&r<=R){
            tag[x]+=d;
            mx[x]+=d;
            return;
        }
        down(x,l,r);
        int mid=l+r>>1;
        if(L<=mid)change(ls[x],l,mid,L,R,d);
        if(R>mid)change(rs[x],mid+1,r,L,R,d);
        up(x);
    }

    int getmx(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return mx[x];
        }
        down(x,l,r);
        int mid=l+r>>1;
        int ret=-2e9;
        if(L<=mid)ret=max(ret,getmx(ls[x],l,mid,L,R));
        if(R>mid)ret=max(ret,getmx(rs[x],mid+1,r,L,R));
        up(x);
        return ret;
    }

    void init(){
        for(int i=1;i<=tot;++i){
            tag[i]=mx[i]=ls[i]=rs[i]=0;
        }
        tot=0;
        mx[0]=-2e9;
        int root=build(0,n);
    }
}T;

struct TT{
	int a[N];
	int n;
	
	void init(){
		for(int i=1;i<=n;++i)a[i]=0;
	}
	
	void add(int x,int d){
		for(;x<=n;x+=x&-x)a[x]+=d;
	}
	
	int sum(int x){
		int r=0;
		for(;x;x-=x&-x)r+=a[x];
		return r;
	}
}B;

int main(){
//	freopen("c.cpp","r",stdin);
	cin>>CC;
	while(CC--){
		ll ans=0;
		n=read();m=read();
		static int q[N];
		q[0]=0;
		for(int i=1;i<=n;++i)a[i]=read(),q[++q[0]]=a[i];
		for(int i=1;i<=m;++i)b[i]=read(),q[++q[0]]=b[i];
		sort(q+1,q+q[0]+1);
		q[0]=unique(q+1,q+q[0]+1)-q-1;
		for(int i=1;i<=n;++i)a[i]=lower_bound(q+1,q+q[0]+1,a[i])-q;
		for(int i=1;i<=m;++i)b[i]=lower_bound(q+1,q+q[0]+1,b[i])-q;
		static int id[N];
		for(int i=1;i<=n;++i)id[i]=i;
		sort(id+1,id+n+1,[](int x,int y){return a[x]<a[y];});
		sort(b+1,b+m+1);
		T.init();
		int l=1;
		for(int i=1;i<=m;++i){
			if(b[i]!=b[i-1]){
				while(l<=n&&a[id[l]]<b[i]){
					if(a[id[l]]==b[i-1])T.change(1,0,n,id[l],n,1);
					else T.change(1,0,n,id[l],n,2);
					++l;
				}
				int l1=l;
				while(l1<=n&&a[id[l1]]==b[i]){
					T.change(1,0,n,id[l1],n,1);
					++l1;
				}
			}
			ans+=l-1-T.mx[1];
		}
		B.n=q[0];
		B.init();
		for(int i=n;i>=1;--i){
			ans+=B.sum(a[i]-1);
			B.add(a[i],1);
		}
		cout<<ans<<endl;
	}
}