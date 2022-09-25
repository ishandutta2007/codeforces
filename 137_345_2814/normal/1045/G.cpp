#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200050
struct node{int x,y,z,ch,v;}s[N<<2],s2[N],S[N<<2];
int n,tr[N],cnt,k;long long as;
void add(int x,int k){for(int i=x;i<200010;i+=i&-i)tr[i]+=k;}
int que(int x){int ans=0;for(int i=x;i;i-=i&-i)ans+=tr[i];return ans;}
bool cmp1(node a,node b){if(a.x==b.x)if(a.y==b.y)return a.z<b.z;else return a.y<b.y;else return a.x<b.x;}
bool cmp2(node a,node b){if(a.y==b.y)return a.z<b.z;else return a.y<b.y;}
bool cmp3(node a,node b){return a.y>b.y;}
void cdq(int l,int r)
{
	if(l>=r)return;
	int mid=(l+r)>>1;
	cdq(l,mid);cdq(mid+1,r);
//	sort(s+l,s+mid+1,cmp2);
//	sort(s+mid+1,s+r+1,cmp2);
	int j=l;
	for(int i=mid+1;i<=r;i++)
	{
		while(s[j].y<=s[i].y&&j<=mid)
		{
			if(s[j].ch==0)
			add(s[j].z,1);
			j++;
		}
		if(s[i].ch==1)
		as+=s[i].v*que(s[i].z);
	}
	for(int i=l;i<j;i++)
	if(s[i].ch==0)
	add(s[i].z,-1);
	int s1=l,s2=mid+1,tmp=l;
	while(s1<=mid||s2<=r)
	{
		if(s2<=r&&(s1==mid+1||cmp2(s[s2],s[s1])))
		S[tmp++]=s[s2++];
		else
		S[tmp++]=s[s1++];
	}
	for(int i=l;i<=r;i++)
	s[i]=S[i];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d%d%d",&s2[i].x,&s2[i].y,&s2[i].z);
	sort(s2+1,s2+n+1,cmp3);
	for(int i=1;i<=n;i++)
	{
		int x=s2[i].x,y=s2[i].y,t=s2[i].z;
		s[++cnt]=(node){x+y,t+k,i,1,1};
		s[++cnt]=(node){x-y-1,t+k,i,1,-1};
		s[++cnt]=(node){x+y,t-k-1,i,1,-1};
		s[++cnt]=(node){x-y-1,t-k-1,i,1,1};
		s[++cnt]=(node){x,t,i+1,0,0};
	}
	sort(s+1,s+cnt+1,cmp1);
	cdq(1,cnt);
	printf("%lld\n",as);
}