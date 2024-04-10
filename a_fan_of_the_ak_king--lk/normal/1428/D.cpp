#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,t,b,x,y,i,ans,a[N],p[N],sta[N],sta2[N],top,top2,top3,sta3[N];
struct str{
	int x,y;
};
vector<str> g;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=n;i>=1;--i)
		if(a[i]==1)
			sta[++top]=i;
		else
			if(a[i]==2)
			{
				if(top==0)
				{
					puts("-1");
					return 0;
				}
				p[i]=sta[top--];
				sta2[++top2]=i;
			}
			else
				if(a[i]==3)
				{
					if(top3!=0)
						p[i]=sta3[top3--];
					else
						if(top2!=0)
							p[i]=sta2[top2--];
						else
							if(top!=0)
								p[i]=sta[top--];
							else
							{
								puts("-1");
								return 0;
							}
					sta3[++top3]=i;
				}
	t=1;
	while(top)
	{
		g.push_back((str){t,sta[top]});
		++t;
		--top;
	}
	for(i=1;i<=n;++i)
		if(p[i])
		{
			g.push_back((str){t,i});
			g.push_back((str){t,p[i]});
			++t;
			if(a[i]==3&&a[p[i]]==1)
			{
				g.push_back((str){t,p[i]});
				++t;
			}
		}
	printf("%d\n",g.size());
	for(auto it:g)
		printf("%d %d\n",it.x,it.y);
}