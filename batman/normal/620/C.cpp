#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N (301*1000)
#define INF ((ll)1e14)
#define MOD ((ll)1e9+7)

int n,a,ans,l=1;
set <ll> s;
vector <pair<ll,ll> > res;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(s.find(a)!=s.end())
		{
			ans++;
			res.push_back({l,i});
			l=i+1;
			s.clear();
		}
		else
			s.insert(a);
	}
	if(ans==0){printf("-1");return 0;}
	printf("%d\n",ans);	
	res[(ll)res.size()-1].second=n;
	for(int i=0;i<res.size();i++)printf("%d %d\n",res[i].first,res[i].second);
    return 0;
}