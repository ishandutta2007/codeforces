#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e6;
int f[N];
struct node{
	int u,v,w;
	inline bool operator <(const node &b)const{
		return w<b.w; 
	}
}b[N];
int find(int x){
	return f[x]=f[x]==x?x:find(f[x]);
}
int n,m,k;
int main()
{
	int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        int ans1=2e9;
        long long ans=0;
        for(int i=1;i<=m;++i){
        	scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
        	ans1=min(ans1,abs(b[i].w-k));
        }
        sort(b+1,b+m+1);
        for(int i=1;i<=n;++i)f[i]=i;
        for(int i=1;i<=m;++i){
        	int xx=find(b[i].u),yy=find(b[i].v);
        	if(xx!=yy){
        		f[xx]=yy;
        		if(b[i].w>k)ans+=b[i].w-k;
        	}
        }
        if(ans==0)printf("%d\n",ans1);
        else printf("%lld\n",ans);
    }
	return 0;
	
}