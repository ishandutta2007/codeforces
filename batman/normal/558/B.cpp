#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll nn,a[101*1000];
map <ll,ll> m,m2;
int main()
{ 
    cin>>nn;
    for(int i=0;i<nn;i++){cin>>a[i],m[a[i]]++;}
    ll maxim=0;
    for(map <ll,ll>::iterator it=m.begin();it!=m.end();it++)
    	maxim=max(maxim,it->second);
    ll ans=1000*1000,p1,p2;	
    for(int x=0,y=0;y<nn;y++)
	{
		m2[a[y]]++;
		if(m2[a[y]]==maxim)
		{
			while(a[x]!=a[y])
			{
				m2[a[x]]--;
				x++;
			}
				
			if(y-x+1ll<ans)	
				ans=y-x+1ll,p1=x+1,p2=y+1;	
		}
		
	}	
	cout<<p1<<" "<<p2;
    return 0;
}