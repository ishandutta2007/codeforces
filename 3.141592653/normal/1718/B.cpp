#include<stdio.h>
#include<bits/stdc++.h>
typedef long long ll;
typedef double db;

struct pii
{
	int a,b;
	pii():a(0),b(0){}
	pii(int aa,int bb):a(aa),b(bb){}
};
bool operator<(const pii&x,const pii&y)
{
	return x.a<y.a;
}
namespace __sol
{
	int n,m;
	ll a[1<<20],f[1<<20],s[1<<20];
	
	void solve()
	{
		scanf("%d",&n);
		std::priority_queue<pii>q;
		long long S=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",a+i),q.push(pii(a[i],i)),S+=a[i];
		long long a=0,b=1,c=1;
		f[1]=f[2]=1,s[1]=1,s[2]=2;
		for(int i=3;i<=44;i++)
			f[i]=f[i-1]+f[i-2],s[i]=f[i]+s[i-1];
		for(int i=1;i<=44;i++)
		{
			if(S==s[i])
			{
				int lst=-1;
				for(int ii=i;ii;ii--)
				{
					pii t=q.top();q.pop();
					//printf("? %d %d\n",t.a,f[ii]);
					if(t.a<f[ii])
					{
						puts("NO");
						return;
					}
					else if(t.b==lst)
					{
						if(!q.size())
						{
							puts("NO");
							return;
						}
						pii w=q.top();q.pop();
						q.push(t);
						if(w.a<f[ii])
						{
							puts("NO");
							return;
						}
						w.a-=f[ii],lst=w.b;
						if(w.a)q.push(w);
					}
					else
					{
						t.a-=f[ii],lst=t.b;
						if(t.a)q.push(t);
					}
				}
				puts("YES");
				return;
			}
		}
		puts("NO");
		return;
	}
}

int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)
	{
		__sol::solve();
	}
}