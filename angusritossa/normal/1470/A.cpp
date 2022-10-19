#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define piz pair<int, pair<int,int> >
typedef long long ll;
const int P = 1e9+7;

const int maxn = 300050;

int t, n, m, k[maxn], c[maxn];

int main()
{
	#ifdef MPS
		freopen("1.in","r",stdin);
		freopen("1.out","w",stdout);
	#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; ++ i) scanf("%d",&k[i]);
		set<pair<int,int> > Set;
		for (int i = 1; i <= m; ++ i) 
		{
			scanf("%d",&c[i]);
			Set.insert(mp(c[i], i));
		}
		long long ans = 0;
		sort(k + 1, k + n + 1);
		reverse(k + 1, k + n + 1);
		for (int i = 1; i <= n; ++ i)
		{
			while (!Set.empty())
			{
				pii h = (*Set.begin());
				if (h.se > k[i]) Set.erase(Set.begin());
				else break;
			}
			if (!Set.empty())
			{
				pii h = (*Set.begin());
				if (h.fi < c[k[i]])
				{
					ans += h.fi;
					Set.erase(Set.begin());
				} 
				else
				{
					
				ans += c[k[i]];
				}
			}
			else
			{
				ans += c[k[i]];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}