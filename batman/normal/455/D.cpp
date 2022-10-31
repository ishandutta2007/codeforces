// I'm back ^_^
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((101*1000))
#define SQ (400)

ll n,q,a[N],lastans;
deque <ll> d[SQ];
ll mp[SQ][N];

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<(n+SQ-1)/SQ;i++)
		for(int j=i*SQ;j<min((i+1)*SQ,n);j++)
			d[i].push_back(a[j]),mp[i][a[j]]++;
			
	scanf("%d",&q);
	while(q--)
	{
		ll t;
		scanf("%d",&t);
		if(t==1)
		{
			ll l,r;
			scanf("%d%d",&l,&r);
			l=(l+lastans-1)%n+1;r=(r+lastans-1)%n+1;if(l>r)swap(l,r);l--;r--;
			ll ex=d[r/SQ][r%SQ];
			mp[r/SQ][d[r/SQ][r%SQ]]--;d[r/SQ].erase(d[r/SQ].begin()+r%SQ);
			mp[l/SQ][ex]++;d[l/SQ].insert(d[l/SQ].begin()+l%SQ,ex);
			for(int i=l/SQ;i<r/SQ;i++)d[i+1].push_front(d[i].back()),mp[i+1][d[i].back()]++,mp[i][d[i].back()]--,d[i].pop_back();
		}
		else
		{
			ll l,r,x,res=0;
			scanf("%d%d%d",&l,&r,&x);
			l=(l+lastans-1)%n+1;r=(r+lastans-1)%n+1;x=(x+lastans-1)%n+1;if(l>r)swap(l,r);l--;
			while(l%SQ!=0 && l<r)res+=(d[l/SQ][l%SQ]==x),l++;
			while(r%SQ!=0 && l<r)r--,res+=(d[r/SQ][r%SQ]==x);
			for(int i=l/SQ;i<r/SQ;i++)res+=mp[i][x];
			lastans=res;
			printf("%d\n",res);
		}
	}
	
	return 0;
}