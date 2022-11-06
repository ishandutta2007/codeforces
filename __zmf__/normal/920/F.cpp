#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+9,M=3000,V=1e6;
int L[M],R[M],tag[N],a[N],n,k,flag,l,r,sum[M],m;
bool lazy[M];
int d[V+9],pr[N],cnt,res,now,qwq;
bool vis[V+9];
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
inline void write(int X)
{
	if(X<0)
	{
		putchar('-');X=-X;
	}
	if(X>9)write(X/10);
	putchar(X%10+'0');
}
inline void update() 
{
    int k;
    if(tag[l]==tag[r]) 
	{
        if(lazy[tag[l]])
            return ;
        for(int i=l;i<=r;i++) 
		{
            k=d[a[i]];
            sum[tag[l]]-=(a[i]-k);
            a[i]=k;
        }
        return ;
    }
    if(!lazy[tag[l]]) 
	{
        for(int i=l;i<=R[tag[l]];i++) 
		{
            k=d[a[i]];
            sum[tag[l]]-=(a[i] - k);
            a[i]=k;
        }
    }
    if(!lazy[tag[r]]) 
	{
        for(int i=L[tag[r]];i<=r;i++) 
		{
            k=d[a[i]];
            sum[tag[r]]-=(a[i] - k);
            a[i]=k;
        }
    }
    for (int i=tag[l]+1;i<tag[r];i++) 
	{
        if(lazy[i])
            continue;
        int tmp=0;
        sum[i]=0;
        for(int j=L[i];j<=R[i];j++) 
		{
            k=d[a[j]];
            if(k>2)tmp++;
            a[j]=k,sum[i]+=a[j];
        }
        if(tmp==0)
            lazy[i]=1;
    }
    return ;
}
inline int query() 
{
    int ans=0;
    if(tag[l]==tag[r]) 
	{
        for(int i=l;i<=r;i++)
            ans+=a[i];
        return ans;
    }
    for(int i=l;i<=R[tag[l]];i++)
        ans+=a[i];
    for (int i=L[tag[r]];i<=r;i++)
        ans+=a[i];
    for (int i=tag[l]+1;i<tag[r];i++)
        ans+=sum[i];
    return ans;
}

inline void init()
{
	d[1]=1;
	for(int i=2;i<=V;i++)
	{
		if(!vis[i])
		{
			d[i]=2;pr[++cnt]=i;
			for(int j=i;j<=V/i;j++)vis[i*j]=1;
		}
		else 
		{
			res=1;qwq=i;
			for(int j=1;j<=cnt&&pr[j]*pr[j]<=qwq;j++)
			{
				now=0;
				while(qwq%pr[j]==0)qwq=qwq/pr[j],now++;
				res=res*(now+1);
			}
			if(qwq!=1)res=res*2;
			d[i]=res;
		}
	}
	return ;
}
signed main() 
{
    n=read(),k=sqrt(n),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=n;i++)
        tag[i]=(i-1)/k+1,sum[tag[i]]+=a[i];
    for(int i=1;i<=tag[n];i++)
        L[i]=R[i-1]+1,R[i]=L[i]+k-1;
    init();
    for(int i=1;i<=m;i++) 
	{
    	flag=read(),l=read(),r=read();
        if(flag==1) 
		{
            update();
        } 
		else 
		{
            write(query());
            puts("");
        }
    }
    return 0;
}