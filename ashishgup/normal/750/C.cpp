#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, val;
int c[N], d[N];

int check(int k)
{
	int currentdiv;
	for(int i=1;i<=n;i++)
	{
		currentdiv=1;
		if(k<1900)
			currentdiv=2;
		if(d[i]!=currentdiv)
		{
			if(currentdiv==2) //Increase
				return 0;
			else //Decrease
				return -1;
		}
		k+=c[i];
	}
	val=k;
	return 1; 
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(check(mid)==-1)
		{
			hi=mid-1;
		}
		else if(check(mid)==0)
		{
			lo=mid+1;
		}
		else
			lo=mid;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n;
	int check1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>d[i];
		check1|=(d[i]==2);
	}
	if(!check1)
	{
		cout<<"Infinity";
		return 0;
	}
	int ans=binsearch(-1e8, 1e8);
	if(check(ans)==1)
		cout<<val;
	else
		cout<<"Impossible";
}