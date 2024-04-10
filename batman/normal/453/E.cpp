#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)101*1000)
#define SQ ((int)400)
#define QS ((int)N/SQ+50)
#define INF ((ll)1e18)

int n,q;
ll b[N];
int m[N],a[N],t_lst[QS];
pair <ll,int> arr[N];
int prt_m[N],prt_a[N];
bool all_same[QS];

void reset(int x)
{
	int l=x*SQ,r=min(n,(x+1)*SQ);
	for(int i=l;i<r;i++)
		arr[i]={(a[i]==0)?INF:(m[i]+a[i]-1)/a[i],i};
	sort(arr+l,arr+r);
	prt_m[l]=m[arr[l].second];
	prt_a[l]=a[arr[l].second];
	for(int i=l+1;i<r;i++)
		prt_m[i]=prt_m[i-1]+m[arr[i].second],
		prt_a[i]=prt_a[i-1]+a[arr[i].second];
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int ex1,ex2,ex3;
		scanf("%d%d%d",&ex1,&ex2,&ex3);
		b[i]=ex1;m[i]=ex2;a[i]=ex3;
	}
	for(int i=0;i<(n+SQ-1)/SQ;i++)reset(i);
	scanf("%d",&q);
	while(q--)
	{
		int t,l,r;
		ll ans=0;
		scanf("%d%d%d",&t,&l,&r);l--;
		int ex=r/SQ;
		if(all_same[ex]==1)for(int i=ex*SQ;i<min(n,(ex+1)*SQ);i++)b[i]=0;
		all_same[ex]=0;
		ex=l/SQ;
		if(all_same[ex]==1)for(int i=ex*SQ;i<min(n,(ex+1)*SQ);i++)b[i]=0;
		all_same[ex]=0;
		
		while(l%SQ && l<r)ans+=min((ll)m[l],b[l]+1LL*a[l]*(t-t_lst[l/SQ])),b[l]=-1LL*a[l]*(t-t_lst[l/SQ]),l++;
		
		ex=r/SQ;
		while(r%SQ && l<r)r--,ans+=min((ll)m[r],b[r]+1LL*a[r]*(t-t_lst[r/SQ])),b[r]=-1LL*a[r]*(t-t_lst[r/SQ]);
		
		for(int i=l/SQ;i<r/SQ;i++)
		{
			int lft=i*SQ,rght=min(n,(i+1)*SQ);
			if(all_same[i])
			{
				ans+=1LL*prt_a[rght-1]*(t-t_lst[i]);
				pair <ll,int> pp;pp={t-t_lst[i],N};
				int id=upper_bound(arr+lft,arr+rght,pp)-(arr+lft)-1;
				if(id>=0)
				{
					ans-=1LL*prt_a[lft+id]*(t-t_lst[i]);
					ans+=prt_m[lft+id];
				}
			}
			else
			{
				for(int j=lft;j<rght;j++)
					ans+=min((ll)m[j],b[j]+1LL*a[j]*(t-t_lst[i]));
			}
			t_lst[i]=t;all_same[i]=1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}