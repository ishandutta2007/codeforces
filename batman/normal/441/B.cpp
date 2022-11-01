#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 3300

ll n,v,a[N],b[N],ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>v;
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i];
		
	
	for(int i=1;i<N;i++)
	{
		ll x=v;
		for(int j=0;j<n;j++)
			if(i==a[j]+1)
			{
				ll ex=min(b[j],x);
				ans+=ex;
				x-=ex;
				b[j]-=ex;
			}
		for(int j=0;j<n;j++)
            if(i==a[j])
            {
                ll ex=min(b[j],x);
				ans+=ex;
				x-=ex;
				b[j]-=ex;
            }	
	}
	cout<<ans;
	return 0;
}