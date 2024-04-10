#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ans;
string s;
vector <pair<ll,char> > v;
int main()
{ 
    cin>>n>>k>>s;
    
    if(k==2)
    {
    	ll cnt1=0,cnt2=0;
    	string a="",b="";
    	for(int i=0;i<n;i++)
    	{
    		if(i&1)
    		{
    			a+='A';
    			b+='B';
    			if(s[i]!='A')
    				cnt1++;
    			else
					cnt2++;	
    		}
    		else
    		{
    			a+='B';
    			b+='A';
    			if(s[i]!='B')
    				cnt1++;
    			else
					cnt2++;	
    		}
    	}
cout<<min(cnt1,cnt2)<<"\n";
    	cout<<((cnt1>cnt2)?b:a);
    	return 0;
    }
    
    
    v.push_back({1,s[0]});
    for(int i=1;i<n;i++)
    {
    	if(s[i]==s[i-1])
    		v[v.size()-1].first++;
    	else
			v.push_back({1,s[i]});	
    }
    string res="";
    for(int i=0;i<v.size();i++)
	{
                ans+=v[i].first/2;
		char p='A';
		while(p==v[i].second || p==v[i+1].second)
			p++;
		for(int j=0;j<v[i].first;j++)
			res+=((j&1)?p:v[i].second);
	}
    cout<<ans<<"\n"<<res;
     
		
    return 0;
}