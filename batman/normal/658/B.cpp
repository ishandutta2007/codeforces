#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (201*1000)

ll n,k,q,a[N];
set <pair<ll,ll> > s;
bool mark[N];

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(q--)
    {
    	ll t,id;
    	cin>>t>>id;
    	if(t==1)
    	{
    		s.insert({a[id],id}),mark[id]=1;
			if((ll)s.size()>k)
			{
				set <pair<ll,ll> >::iterator it=s.begin();
				mark[it->second]=0;
				s.erase(it);	
			}	
		}
		else
		{
			cout<<((mark[id])?"YES\n":"NO\n");
		}
	}
    return 0;
}