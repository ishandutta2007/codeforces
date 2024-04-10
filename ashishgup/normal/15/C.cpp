#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
int x[N], m[N];

int get(int x)
{
	if(x%4==0)
		return x;
	if(x%4==1)
		return 1;
	if(x%4==2)
		return x+1;
	if(x%4==3)
		return 0;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>m[i];
		int cur=get(x[i]+m[i]-1) ^ get(x[i]-1);
		ans^=cur;
	}	
	if(!ans)
		cout<<"bolik";
	else
		cout<<"tolik";
	return 0;
}