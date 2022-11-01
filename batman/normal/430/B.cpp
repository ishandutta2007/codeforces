#include <bits/stdc++.h>
using namespace std;

int n,k,x1,ans;
int s[200];

int destroy(vector <int> x)
{
	if(x.size()<3)
		return 0;
	int res=0;
	for(int i=0;i<x.size();i++)
	{
		int ex=1;
		for(int j=i+1;x[j]==x[i] && j<x.size();j++)
			ex++;
		if(ex>=3)
		{
			if(x.size()==ex)
				return res+ex;
			res+=ex;
			vector <int> p;
			for(int j=0;j<i;j++)
				p.push_back(x[j]);
			for(int j=i+ex;j<x.size();j++)
				p.push_back(x[j]);
			x=p;		
			i=-1;	
		}
	}
	return res;
}

int main()
{
    cin>>n>>k>>x1;
    for(int i=0;i<n;i++)
    	cin>>s[i];
    for(int i=0;i<n-1;i++)
    	if(s[i]==s[i+1] && s[i]==x1)
    	{
    		vector <int> p;
    		for(int j=0;j<i;j++)
    			p.push_back(s[j]);
    		for(int j=i+2;j<n;j++)
				p.push_back(s[j]);
			//cerr<<p<<endl;	
			ans=max(ans,2+destroy(p));		
    	}
    cout<<ans<<endl;	
    return 0;
}