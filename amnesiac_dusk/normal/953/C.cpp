#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pii pair<int , int>
#define pll pair<long long int,long long int>
#define mod 1000000007
#define inf 1e18+7
#define eps 0.00001
#define endl '\n'
int main()
{
	fastio;
	/*
	#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
    		freopen("output.txt", "w", stdout);
	#endif
	*/
	ll n;
	cin>>n;
	int a[n];
	bool b1=0,b0=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			b1=1;
		else
			b0=1;
	} 
	if((b0==1 && b1==0)||(b0==0 && b1==1))
	{
		cout<<"YES";
		return 0;
	}
	//cout<<"hi";
	ll i,j;
	for(i=1;i<n;i++)
		if(a[i]!=a[i-1])
			break;
	ll l=i;

	for(i=l;i<n;i++)
	{
		for(j=i+1;j<n;j++)
			if(a[j]!=a[i])
				break;
		if((j-i)!=l)
			break;
		i=j-1;		
	}	
	if(i==n)
		cout<<"YES";
	else
		cout<<"NO";
}