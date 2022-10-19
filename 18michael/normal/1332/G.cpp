#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
#define Mx 17
#define eps 1e-10
using namespace std;
int n,q,st1_t=0,st2_t=0,len;
int a[200002],st1[200002],st2[200002],suf1[200002],suf2[200002],suf3[200002],suf4[200002],suf5[200002],cnt[200002],pre1[200002],pre2[200002];
set<int> s,s1,s2;
set<int>::iterator it;
struct aaa
{
	int a,b,c;
}A[200002][18],tmpA;
struct bbb
{
	int a,b,c,d;
}B[200002][18],tmpB;
inline aaa mergeA(aaa a,aaa b)
{
	return a.c<b.c? a:b;
}
inline bbb mergeB(bbb a,bbb b)
{
	return a.d<b.d? a:b;
}
inline bool check3(int x,int y)
{
	len=log2(y-x+1)+eps,tmpA=mergeA(A[x][len],A[y-(1<<len)+1][len]);
	if(tmpA.c>y)return 0;
	printf("3\n%d %d %d\n",tmpA.a,tmpA.b,tmpA.c);
	return 1;
}
inline bool check4(int x,int y)
{
	len=log2(y-x+1)+eps,tmpB=mergeB(B[x][len],B[y-(1<<len)+1][len]);
	if(tmpB.d>y)return 0;
	printf("4\n%d %d %d %d\n",tmpB.a,tmpB.b,tmpB.c,tmpB.d);
	return 1;
}
int main()
{
	scanf("%d%d",&n,&q),st1[0]=st2[0]=n+1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),s.insert(i),A[i][0]=(aaa){0,0,n+1};
	for(int i=n;i;--i)
	{
		while(st1_t && a[i]<=a[st1[st1_t]])--st1_t;
		while(st2_t && a[i]>=a[st2[st2_t]])--st2_t;
		suf1[i]=st1[st1_t],suf2[i]=st2[st2_t],st1[++st1_t]=st2[++st2_t]=i;
	}
	st1_t=st2_t=0;
	for(int i=1;i<=n;++i)
	{
		while(st1_t && a[i]<=a[st1[st1_t]])--st1_t;
		while(st2_t && a[i]>=a[st2[st2_t]])--st2_t;
		pre1[i]=st1[st1_t],pre2[i]=st2[st2_t],A[st1[st1_t]][0]=mergeA(A[st1[st1_t]][0],(aaa){pre1[i],i,suf1[i]}),A[st2[st2_t]][0]=mergeA(A[st2[st2_t]][0],(aaa){pre2[i],i,suf2[i]}),st1[++st1_t]=st2[++st2_t]=i;
	}
	st1_t=st2_t=0;
	for(int i=n;i;--i)
	{
		while(st1_t && a[i]<a[st1[st1_t]])
		{
			if(!(--cnt[st1[st1_t]]))s.insert(st1[st1_t]);
			s1.erase(st1[st1_t]),--st1_t;
		}
		while(st2_t && a[i]>a[st2[st2_t]])
		{
			if(!(--cnt[st2[st2_t]]))s.insert(st2[st2_t]);
			s2.erase(st2[st2_t]),--st2_t;
		}
		st1[++st1_t]=st2[++st2_t]=i,s1.insert(i),s2.insert(i),cnt[i]=2,s.erase(i);
		if((it=s.upper_bound(max(suf1[i],suf2[i])))==s.end())suf3[i]=n+1;
		else
		{
			suf3[i]=(*it);
			if((it=s1.lower_bound(suf3[i]))!=s1.begin())--it,suf4[i]=(*it);
			if((it=s2.lower_bound(suf3[i]))!=s2.begin())--it,suf5[i]=(*it);
		}
		B[i][0]=(bbb){i,min(suf4[i],suf5[i]),max(suf4[i],suf5[i]),suf3[i]};
	}
	for(int i=1;i<=Mx;++i)for(int j=1;j+(1<<i)-1<=n;++j)A[j][i]=mergeA(A[j][i-1],A[j+(1<<(i-1))][i-1]),B[j][i]=mergeB(B[j][i-1],B[j+(1<<(i-1))][i-1]);
	for(int x,y;q--;)
	{
		scanf("%d%d",&x,&y);
		if(!check4(x,y) && !check3(x,y))puts("0");
	}
	return 0;
}