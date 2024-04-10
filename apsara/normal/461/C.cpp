#include <set>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <vector>
#include <ctime>
#include <queue>
#include <list>
#include <map>
using namespace std;
int tree[200022];
int dep[200022];
void update(int pos,int c)
{
	while(pos<=100011)
	{
		tree[pos]+=c;
		pos+=pos&-pos;
	}
}
int query(int pos)
{
	int ss=0;
	while(pos)
	{
		ss+=tree[pos];
		pos-=pos&-pos;
	}
	return ss;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	int len=n,op=0;
	int st=1,ed=n;
	for(int i=1;i<=n;i++)
	{
		update(i,1);
		dep[i]=1;
	}
	while(q--)
	{
		int o;
		scanf("%d",&o);
		// printf("%d %d %d %d\n",st,ed,len,op);
		if(o==1)
		{
			int p;
			scanf("%d",&p);
			// cout<<"!!!"<<p<<endl;
			if(p*2<=len)
			{
				if(op==0)
				{
					for(int i=st;i<st+p;i++)
					{
						int v=2*p+2*st-i-1;
						int p1=dep[i];
						update(i,-p1);
						dep[i]=0;
						dep[v]+=p1;
						update(v,p1);
					}
					st+=p;
				}
				else
				{
					for(int i=ed;i>ed-p;i--)
					{
						int v=2*ed-2*p+1-i;
						int p1=dep[i];
						update(i,-p1);
						dep[i]=0;
						dep[v]+=p1;
						update(v,p1);
					}
					ed-=p;
				}
				len-=p;
			}
			else
			{
				p=len-p;
				if(op==0)
				{
					for(int i=ed;i>ed-p;i--)
					{
						int v=2*ed-2*p+1-i;
						int p1=dep[i];
						update(i,-p1);
						dep[i]=0;
						dep[v]+=p1;
						update(v,p1);
					}
					op=1;
					ed-=p;
				}
				else
				{
					for(int i=st;i<st+p;i++)
					{
						int v=2*p+2*st-i-1;
						int p1=dep[i];
						update(i,-p1);
						dep[i]=0;
						dep[v]+=p1;
						update(v,p1);
					}
					op=0;
					st+=p;
				}
				len-=p;
			}
		}
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			// a++,b++;
			if(op==0)
			{
				a+=st;
				b+=st;
				printf("%d\n",query(b-1)-query(a-1));
			}
			else
			{
				a=ed-a;
				b=ed-b;
				printf("%d\n",query(a)-query(b));
			}
		}
	}
}