#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll ans;
map <int,int> mp;
multiset <int> s;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){int x;scanf("%d",&x);mp[x]++;ans+=x;}
    for(auto it=mp.end();it!=mp.begin();)
    {
    	multiset <int> now;
    	it--;
    	int x=it->first,cnt=it->second;
    	while(cnt && s.size() && *s.begin()==0)
    		now.insert(x),s.erase(s.begin()),cnt--;
    	while(cnt>1 && s.size())
    	{
    		int y=*s.begin();
    		if(y>=2*x)break;
    		s.erase(s.begin());cnt-=2;
    		if(y<x)now.insert(x),now.insert(x);
    		else now.insert(2*x-y),now.insert(y);
		}
		if(cnt && s.size() && *s.begin()<x)
			s.erase(s.begin()),now.insert(x),now.insert(0),cnt--;
		while(cnt)now.insert(0),cnt--;
		while(now.size())s.insert(*now.begin()),now.erase(now.begin());
	}
	for(auto u:s)ans-=u;
	cout<<ans<<"\n";
    return 0;
}