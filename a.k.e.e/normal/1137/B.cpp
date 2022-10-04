#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=500005;

int n,m,slen;
char s[MAXN],t[MAXN];
int res[MAXN];
struct Suffix
{
	int x,y,id;
	Suffix(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
	inline bool operator ==(const Suffix &b)const {return x==b.x && y==b.y;}
}a[MAXN],b[MAXN];
int wcnt[MAXN],sa[MAXN],rk[MAXN],height[MAXN];

void buildsa(const char *s)
{
	int tot=0,k=1;
	for(int i=1;i<=n;i++)wcnt[s[i]-'0']++;
	wcnt[1]+=wcnt[0];
	for(int i=n;i>0;i--)sa[wcnt[s[i]-'0']--]=i;
	for(int i=1;i<=n;i++)
		if(s[sa[i]]==s[sa[i-1]])rk[sa[i]]=tot;
		else rk[sa[i]]=++tot;
	while(k<=n)
	{
		for(int i=1;i<=n;i++)a[i]=Suffix(rk[i],i+k>n?0:rk[i+k],i);
		memset(wcnt,0,sizeof(wcnt));
		for(int i=1;i<=n;i++)wcnt[a[i].y]++;
		for(int i=1;i<=n;i++)wcnt[i]+=wcnt[i-1];
		for(int i=n;i>0;i--)b[wcnt[a[i].y]--]=a[i];
		memset(wcnt,0,sizeof(wcnt));
		for(int i=1;i<=n;i++)wcnt[b[i].x]++;
		for(int i=1;i<=n;i++)wcnt[i]+=wcnt[i-1];
		for(int i=n;i>0;i--)a[wcnt[b[i].x]--]=b[i];
		tot=0;
		for(int i=1;i<=n;i++)
			if(a[i]==a[i-1])rk[a[i].id]=tot;
			else rk[a[i].id]=++tot;
		if(tot==n)break;
		k<<=1;
	}
	for(int i=1;i<=n;i++)sa[rk[i]]=i;
	k=0;
	for(int i=1;i<=n;i++)
	{
		if(k)k--;
		for(int t=sa[rk[i]-1];i+k<=n && t+k<=n && s[i+k]==s[t+k];k++);
		height[rk[i]]=k;
	}
}

int _log2[MAXN],rmq[MAXN][21];
void SparseTable()
{
    int t=0;
    for(int i=1;i<=n;i++)
    {
    	rmq[i][0]=height[i];
        if(i>=(1<<(t+1)))t++;
        _log2[i]=t;
    }
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}
inline int RMQ(int l,int r)
{
	if(l>r)swap(l,r);
	++l;
    int t=_log2[r-l+1];
    return min(rmq[l][t],rmq[r-(1<<t)+1][t]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%s%s",s+1,t+1);
    n=strlen(t+1);
    slen=m=strlen(s+1);
    int cnt1=0,cnt0=0;
    for(int i=1;i<=m;i++)
    	if(s[i]=='1')++cnt1;
    	else ++cnt0;
    buildsa(t);
    SparseTable();
    int ans=0;
    for(int i=n-1;i>0;i--)
    	if(RMQ(rk[1],rk[n-i+1])>=i)
    		{ans=i;break;}
//cout<<ans<<endl;
	bool flag=1;
    for(int i=n;i>n-ans;i--)
    {
	    if(t[i]=='1')--cnt1,res[m--]=1;
	    else --cnt0,res[m--]=0;
	    if(cnt0<0 || cnt1<0){flag=0;++m;cnt0=max(cnt0,0);cnt1=max(cnt1,0);break;}
	}
	while(flag)
	{
	    for(int i=n-ans;i>0;i--)
	    {
	    	if(!m){flag=0;break;}
	    	if(t[i]=='1')--cnt1,res[m--]=1;
	    	else --cnt0,res[m--]=0;
	    	if(cnt0<0 || cnt1<0){flag=0;++m;cnt0=max(cnt0,0);cnt1=max(cnt1,0);break;}
	    }
	}
	if(cnt1)for(int i=m;i>0;i--)res[i]=1;
	else for(int i=m;i>0;i--)res[i]=0;
	for(int i=1;i<=slen;i++)
		putchar(res[i]+'0');
    return 0;
}