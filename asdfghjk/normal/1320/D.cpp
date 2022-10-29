#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int N=200005,md1=19260817,md2=998244353;
int n,q,cnt,id[N],num[N],nxt[N],lst[N],pw1[N],pw2[N],hs1[N],hs2[N],p[N],i,j,k;
char s[N];
int Hash1(int l,int r)
{
	if(l>r)
		return 0;
	return (hs1[r]-1ll*hs1[l-1]*pw1[r-l+1]%md1+md1)%md1;
}
int Hash2(int l,int r)
{
	if(l>r)
		return 0;
	return (hs2[r]-1ll*hs2[l-1]*pw2[r-l+1]%md2+md2)%md2;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	pw1[0]=pw2[0]=1;
	for(i=1;i<=n;++i)
		pw1[i]=pw1[i-1]*131ll%md1,pw2[i]=pw2[i-1]*131ll%md2;
	for(i=1;i<=n;++i)
	{
		num[i]=num[i-1]+(s[i]=='1');
		if(s[i]=='0')
		{
			id[i]=++cnt;
			p[cnt]=i;
		}
	}
	for(i=1;i<cnt;++i)
		hs1[i]=(hs1[i-1]*131ll+(p[i+1]-p[i])%2)%md1,hs2[i]=(hs2[i-1]*131ll+(p[i+1]-p[i])%2)%md2;
	nxt[n]=n+1;
	for(i=n;i>=1;--i)
		if(s[i]=='0')
			nxt[i-1]=i;
		else
			nxt[i-1]=nxt[i];
	lst[1]=0;
	for(i=1;i<=n;++i)
		if(s[i]=='0')
			lst[i+1]=i;
		else
			lst[i+1]=lst[i];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&i,&j,&k);
		if(num[i+k-1]-num[i-1]!=num[j+k-1]-num[j-1])
		{
			puts("No");
			continue;
		}
		if(num[i+k-1]-num[i-1]==k)
		{
			puts("Yes");
			continue;
		}
		if((nxt[i-1]-i)%2!=(nxt[j-1]-j)%2||(i+k-lst[i+k])%2!=(j+k-lst[j+k])%2)
		{
			puts("No");
			continue;
		}
		if(Hash1(id[nxt[i-1]],id[lst[i+k]]-1)==Hash1(id[nxt[j-1]],id[lst[j+k]]-1)&&Hash2(id[nxt[i-1]],id[lst[i+k]]-1)==Hash2(id[nxt[j-1]],id[lst[j+k]]-1))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}