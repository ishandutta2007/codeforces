#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (101*1000)
ll n,k,a,ans,mp[111];
set <pair <ll,ll> > s;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
	{
		cin>>a,ans+=a/10;
		mp[a]++;
		if(a<100)s.insert({10-a%10,a});	
	}
	
    while(k && s.size())
    {
    	//cout<<s.begin()->first<<endl;
    	if(s.begin()->first>k)
    		break;
    	k-=s.begin()->first;
    	ans++;
    	ll ex2=s.begin()->second;
    	//cout<<ex2<<endl;
    	mp[ex2]--;
    	if(!mp[ex2])
    		s.erase(s.begin());
		if(ex2<90)
			s.insert({10,ex2/10*10+10}),mp[ex2/10*10+10]++;
	}
    cout<<ans;
	return 0;
}