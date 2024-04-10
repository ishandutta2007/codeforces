#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define MAX (5000*1000)
#define ll long long

ll n,prm[MAX],pli[MAX],p,q;
bool mrk[MAX];

bool plind(ll x)
{
	ll v[10],cnt=0;
	while(x)
	{
		v[cnt++]=x%10;
		x/=10;
	}
	for(int i=0;i<cnt/2;i++)
		if(v[i]!=v[cnt-i-1])
			return 0;
	return 1;		
}

int main()
{ 
    cin>>p>>q;
    for(int i=2;i<MAX;i++)
    {
    	if(!mrk[i])
    	{
    		for(int j=i*2;j<MAX;j+=i)
    			mrk[j]=1;
    		prm[i]++;	
    	}
    	prm[i]+=prm[i-1];	
    }
    for(int i=1;i<MAX;i++)
		pli[i]=pli[i-1]+(plind(i));	
	
	for(int i=MAX-1;i>=1;i--)
		if((ld)prm[i]*q<=p*(ld)pli[i])
			return cout<<i,0;		
	
	cout<<"plindromic tree is better than splay tree";		
    return 0;
}