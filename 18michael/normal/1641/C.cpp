#include<bits/stdc++.h>
using namespace std;
int n,q,t;
int rt[200002]={},mx[200002]={};
typedef pair<int,int> P;
set<P> s;
set<P>::iterator it;
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int t,l,r,x;q--;)
	{
		scanf("%d",&t);
		if(!t)
		{
			scanf("%d%d%d",&l,&r,&x);
			if(!x)
			{
				if(!rt[l])rt[l]=mx[l]=l;
				for(x=r,getroot(l);;)
				{
					if(r<=l)break;
					if(!rt[r])rt[r]=mx[r]=r;
					getroot(r);
					if(rt[r]==rt[l])break;
					t=rt[r]-1,mx[rt[l]]=max(mx[rt[l]],mx[rt[r]]),rt[rt[r]]=rt[l],r=t;
				}
				r=x;
				if(r<n && rt[r+1])getroot(l),getroot(r+1),mx[rt[l]]=max(mx[rt[l]],mx[rt[r+1]]),rt[rt[r+1]]=rt[l];
				if(l>1 && rt[l-1])getroot(l),getroot(l-1),mx[rt[l-1]]=max(mx[rt[l-1]],mx[rt[l]]),rt[rt[l]]=rt[l-1];
			}
			else
			{
				it=s.lower_bound(P(l,0));
				if(it==s.end() || (*it).second>r)
				{
					while((it=s.lower_bound(P(l,0)))!=s.begin())
					{
						if((*(--it)).second<r)break;
						s.erase(it);
					}
					s.insert(P(l,r));
				}
			}
		}
		else
		{
			scanf("%d",&x),getroot(x);
			if(rt[x])
			{
				puts("NO");
				continue;
			}
			if(x==1)l=1;
			else getroot(x-1),l=(rt[x-1]? rt[x-1]:x);
			if(x==n)r=n;
			else getroot(x+1),r=(mx[rt[x+1]]? mx[rt[x+1]]:x);
			it=s.lower_bound(P(l,0));
			puts((it!=s.end() && (*it).second<=r)? "YES":"N/A");
		}
	}
	return 0;
}