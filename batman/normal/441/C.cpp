#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 3300

ll n,m,k;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	ll i=1,j=1;
	ll ex=k;
	while(k>1)
	{
		if(i&1)
		{
			if(j==m)
				cout<<2<<" "<<i<<" "<<j<<" "<<i+1<<" "<<j<<"\n",i++,j=m-1;
			else
			{
				cout<<2<<" "<<i<<" "<<j<<" "<<i<<" "<<j+1<<"\n";
				j+=2;
				if(j>m)
					j=m,i++;
			}	
			k--;
		}
		else
		{
			if(j==1)
				cout<<2<<" "<<i<<" "<<j<<" "<<i+1<<" "<<j<<"\n",i++,j=1;
			else
			{
				cout<<2<<" "<<i<<" "<<j<<" "<<i<<" "<<j-1<<"\n";
				j-=2;
				if(j<1)
					j=1,i++;
			}	
			k--;
		}
		
	}
	cout<<n*m-ex*2+2<<" ";
	if(i&1)
	{
		for(;j<=m;j++)
			cout<<i<<" "<<j<<" ";	
	}
	else
	{
		for(;j>0;j--)
			cout<<i<<" "<<j<<" ";	
	}
	for(int q=i+1;q<=n;q++)
	{
		if(q%2==0)
		{
			for(int p=m;p>0;p--)
				cout<<q<<" "<<p<<" ";
		}
		else
		{
			for(int p=1;p<=m;p++)
				cout<<q<<" "<<p<<" ";
		}
	}
	
	return 0;
}