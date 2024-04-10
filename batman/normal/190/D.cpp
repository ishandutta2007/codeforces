#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[401*1000],p,ans;
bool mark[401*1000];
map <ll,ll> mp;
ifstream fin("input.txt");
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    	cin>>a[i];
    for(int i=0;i<n;i++)
	{
		while(p<n)
		{
			if(!mark[p])
				mp[a[p]]++;
			mark[p]=1;	
			if(mp[a[p]]>=k)
			{
				ans+=n-p;
				break;
			}
			p++;
		}
		mp[a[i]]--;
	}	
	cout<<ans;
    return  0;
}