#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=4e5;
struct re{
	int a,b,c;
}e[N*2];
int head[N],n,m,ve[N],t1[N],t2[N],ans[N],l;
#define ll long long
void arr(int x,int y)
{
	e[++l].a=head[x];
	e[l].b=y;
	head[x]=l;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m; l=0;
		rep(i,1,m)
		{
			int x,y;
			cin>>x>>y;
			arr(x,y); arr(y,x);
		}
		int cnt=0,cnt3=0;
		int now=0;
		ve[++cnt]=1;
		while (now<cnt)
		{
			now++;
			if (!t1[ve[now]])
			{
				int x=ve[now]; t1[x]=1;
				ans[++cnt3]=x;
				t1[x]=1;
				for (int u=head[x];u;u=e[u].a)
				{
					int v=e[u].b;
					if (!t1[v])
					{
						t1[v]=1;
						for(int u2=head[v];u2;u2=e[u2].a)
						{
							int v2=e[u2].b;
						    if (!t1[v2]&&!t2[v2])	
						    {
						    	ve[++cnt]=v2; t2[v2]=1;
						    }
						}
					}
				}
			}
		}
		int tt=1;
		rep(i,1,n) if (!t1[i]) tt=-1;
		if (tt==-1) cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			cout<<cnt3<<endl;
			rep(i,1,cnt3) cout<<ans[i]<<" ";
			cout<<endl; 
		}
		rep(i,1,n) t1[i]=t2[i]=0;
		rep(i,1,n) head[i]=0;
	}
	return 0;
}