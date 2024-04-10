#include <bits/stdc++.h>
#pragma GCC optimize 2
#pragma GCC optimize 3
using namespace std;
int s1[1000005],s2[1000005],sz1,sz2,n,l[2200005],r[2200005],cnt[1000005];
short CNT[100005];
long long a[1000005];
inline char read(){
    static const int IO_LEN=1024*1024;
    static char buf[IO_LEN],*ioh,*iot;
    if(ioh==iot){
        iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
        if(ioh==iot) return -1;
    }
    return *ioh++;
}
template<class T>inline void read(T &x){
    static int iosig;static char ioc;
    for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
    for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
    if(iosig) x=-x;
}
inline int Cnt(long long x)
{
	return CNT[x&65535]+CNT[(x>>16)&65535]+CNT[(x>>32)&65535]+CNT[(x>>48)&65535];
}
struct stree
{
	signed sum1,sum0,ans;
	short cov1,cov0;
}t[2200005];
inline void give0(int now,int x)
{
	t[now].cov0=x;
	if(x==1)
	{
		t[now].ans=t[now].sum1;
		t[now].sum0=r[now]-l[now]+1;
	}
	else t[now].ans=t[now].sum0=0;
}
inline void give1(int now,int x)
{
	t[now].cov1=x;
	if(x==1)
	{
		t[now].ans=t[now].sum0;
		t[now].sum1=r[now]-l[now]+1;
	}
	else t[now].ans=t[now].sum1=0;
}
inline void pd(int now)
{
	if(t[now].cov0)
	{
		give0(now*2,t[now].cov0);
		give0(now*2+1,t[now].cov0);
		t[now].cov0=0;
	}
	if(t[now].cov1)
	{
		give1(now*2,t[now].cov1);
		give1(now*2+1,t[now].cov1);
		t[now].cov1=0;
	}
}
inline void upd(int now)
{
	t[now].sum0=t[now*2].sum0+t[now*2+1].sum0;
	t[now].sum1=t[now*2].sum1+t[now*2+1].sum1;
	t[now].ans=t[now*2].ans+t[now*2+1].ans;
}
inline void build(int now,int L,int R)
{
	l[now]=L,r[now]=R;
	t[now].cov0=t[now].cov1=t[now].sum0=t[now].sum1=t[now].ans=0;
	if(L==R) return ;
	int mid=(L+R)/2;
	build(now*2,L,mid),build(now*2+1,mid+1,R);
}
inline void cov0(int now,int L,int R,int x)
{
	if(l[now]==L&&r[now]==R)
	{
		give0(now,x);
		return ;
	}
	pd(now);
	if(r[now*2]>=R) cov0(now*2,L,R,x);
	else if(l[now*2+1]<=L) cov0(now*2+1,L,R,x);
	else cov0(now*2,L,r[now*2],x),cov0(now*2+1,l[now*2+1],R,x);
	upd(now);
}
inline void cov1(int now,int L,int R,int x)
{
	if(l[now]==L&&r[now]==R)
	{
		give1(now,x);
		return ;
	}
	pd(now);
	if(r[now*2]>=R) cov1(now*2,L,R,x);
	else if(l[now*2+1]<=L) cov1(now*2+1,L,R,x);
	else cov1(now*2,L,r[now*2],x),cov1(now*2+1,l[now*2+1],R,x);
	upd(now);
}
inline int query()
{
	return t[1].ans;
}
signed main(int argc, char** argv) {
	read(n);
	for(int i=1;i<=65535;i++) CNT[i]=CNT[i^i&-i]+1;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		cnt[i]=Cnt(a[i]);
	}
	long long ans=0;
	build(1,1,n);
	int now=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) ans+=++now;
		else now=0;
	}
	for(int i=1;i<=59;i++)
	{
		sz1=sz2=0;
		cov0(1,1,n,2),cov1(1,1,n,2);
		for(int j=1;j<=n;j++)
		{
			int flag=0;
			while(sz1&&a[s1[sz1]]<a[j])
			{
				if(cnt[s1[sz1]]==i) flag=1;
				--sz1;
			}
			if(cnt[j]==i)
				cov0(1,s1[sz1]+1,j,1);
			else if(flag) cov0(1,s1[sz1]+1,j,2);
			flag=0;
			while(sz2&&a[s2[sz2]]>a[j])
			{
				if(cnt[s2[sz2]]==i) flag=1;
				--sz2;
			}
			if(cnt[j]==i)
				cov1(1,s2[sz2]+1,j,1);
			else if(flag) cov1(1,s2[sz2]+1,j,2);
			s1[++sz1]=j,s2[++sz2]=j;
			ans+=query();
		}
	}
	cout << ans;
	return 0;
}//6