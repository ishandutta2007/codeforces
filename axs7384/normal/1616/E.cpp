#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e12;
const int N=200005;
int T,n;
char s[N],t[N];
set<int> st[30];
struct BIT
{
	int f[N];
	inline void clear()
	{
		for (int i=0;i<=n;++i)
			f[i]=0;
	}
	inline void add(int x)
	{
		for (;x<=n;x+=x&(-x))
			++f[x];
	}
	inline int ask(int x)
	{
		int ans=0;
		for (;x;x-=x&(-x))
			ans+=f[x];
		return ans;
	}
}F;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		int p=0;
		for (int i=1;i<=n;++i)
			if (s[i]==t[i])
				p=i;
			else
				break;
		if (p!=n&&s[p+1]<t[p+1])
		{
			puts("0");
			continue;
		}
		for (int i=0;i<26;++i)
			st[i].clear();
		F.clear();
		ll ans=inf,sum=0;
		for (int i=1;i<=n;++i)
			st[s[i]-'a'].insert(i);
		// cout<<"??"<<endl;
		for (int i=1;i<=n;++i)
		{
			int pos=n+1;
			for (int j=0;j<t[i]-'a';++j)
				if (!st[j].empty())
					pos=min(pos,*st[j].begin());
			if (pos!=n+1)
			{
				ans=min(ans,sum+pos-F.ask(pos)-1);
			}
			// puts("...");
			if (st[t[i]-'a'].empty())
				break;
			int x=*st[t[i]-'a'].begin();
			// cout<<"!"<<x<<endl;
			sum+=x-F.ask(x)-1;
			F.add(x);
			st[t[i]-'a'].erase(st[t[i]-'a'].begin());
		}
		if (ans!=inf)
			printf("%lld\n",ans);
		else
			puts("-1");
	}
}