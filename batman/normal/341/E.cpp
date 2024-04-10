#include <bits/stdc++.h>
using namespace std;
#define N (1010)

int n,a[N],sum,gcd;
pair<int,int> b[3];
vector <pair<int,int> > ans;

void decrease()
{
	while(1)
	{
		sort(b,b+3);
		if(b[0].first==0)return ;
		int q=b[1].first/b[0].first;
		while(q)
		{
			if(q%2)
			{
				ans.push_back({b[0].second+1,b[1].second+1});
				b[1].first-=b[0].first;
				b[0].first*=2;
			}
			else
			{
				ans.push_back({b[0].second+1,b[2].second+1});
				b[2].first-=b[0].first;
				b[0].first*=2;
			}
			q/=2;
		}
	}
}

int main()
{
	scanf("%d",&n);
	int cnt=0;
	for(int i=0;i<n;i++)scanf("%d",&a[i]),cnt+=(a[i]==0);
	if(cnt>n-2)return cout<<-1,0;
	set<pair<int,int> > s;
	for(int i=0;i<n;i++)s.insert({a[i],i});
	while(s.begin()->first==0)s.erase(s.begin());
	while((int)s.size()>2)
	{
		set<pair<int,int> >::iterator it=s.begin();
		for(int i=0;i<3;i++,it++)
			b[i]=*it;
		decrease();
		for(int i=0;i<3;i++)s.erase(s.begin());
		for(int i=0;i<3;i++)if(b[i].first!=0)s.insert(b[i]);
	}
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	return 0;
}