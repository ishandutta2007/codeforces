#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n,p,a,ans;
vector <pair<ll,ll> > v1,v2;
int main()
{ 
    cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p>>a;
		if(p<0)
			v1.push_back({p,a});
		if(p>0)
			v2.push_back({p,a});
		if(p==0)
			ans+=a;		
	}
	sort(v1.begin(),v1.end()),sort(v2.begin(),v2.end());
	int i,j;
	for(i=0,j=v1.size()-1;i<v2.size() && j>=0;j--,i++)
	{
		ans+=v1[j].second+v2[i].second;
	}
	if(i==v2.size() && j!=-1)
		ans+=v1[j].second;
	else if(j==-1 && i!=v2.size())
		ans+=v2[i].second;
	cout<<ans;		
	
		
				
    return 0;
}