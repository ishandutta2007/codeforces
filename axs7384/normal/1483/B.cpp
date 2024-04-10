#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],in[N],l,r;
// pair<int,int> q[N*3];
int q[N*3];
int nxt[N];
int n,t;
vector<int> v;
inline int gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			in[i]=1;
		}
		// puts("???");
		for (int i=1;i<=n;++i)
			//q[i]=make_pair(i,1);
		{
			q[i]=i;
			nxt[i]=i%n+1;
		}
		l=1;
		r=n;
		v.clear();
		while (l<=r)
		{
			// int x=q[l].first;
			// int y=(x+q[l].second-1)%n+1;
			int x=q[l];
			int y=nxt[x];
			// cout<<t<<' '<<x<<' '<<y<<endl;
			if (!in[x]||!in[y])
			{
				++l;
				continue;
			}
			if (gcd(a[x],a[y])==1)
			{
				// q[++r]=(make_pair(x,q[l].second+1));
				q[++r]=x;
				nxt[x]=nxt[y];
				v.push_back(y);
				in[y]=0;
			}
			++l;
		}
		printf("%d ",v.size());
		for (unsigned i=0;i<v.size();++i)
			printf("%d ",v[i]);
		puts("");
	}
	return 0;
}