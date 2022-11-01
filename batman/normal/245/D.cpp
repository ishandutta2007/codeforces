#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	ll ans=0;
    	bool mark[40]={0};
    	for(int j=0;j<n;j++)
    	{
    		cin>>a;
    		if(a==-1)
				continue;
    		for(int k=0;a;k++,a/=2)
				if(a%2)
					mark[k]=1;
    	}
    	for(int j=0,k=1;j<40;j++,k<<=1)
    		if(mark[j])
    			ans+=k;
    	cout<<ans<<" ";		
    }
    
    return  0;
}