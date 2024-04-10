#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (301*1000)
#define INF ((ll)1e9)

ll n;
bool a[N];

void check(ll x)
{
	for(int i=0;i<x;i++)
	{
		bool mark=1;
		for(int j=i;j<n;j+=x)
			if(!a[j])
			{
				mark=0;
				break;
			}
		if(mark)
		{
			cout<<"YES";
			exit(0);	
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>a[i];
    for(int i=1;i<=sqrt(n);i++)
		if(n%i==0)
		{
			if(i>=3)check(n/i);
			if(n/i>=3)check(i);	
		}		
	cout<<"NO";	
    
    return 0;
}