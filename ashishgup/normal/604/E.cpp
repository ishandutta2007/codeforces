#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, nim=0;
int a[N];
vector<int> v={0, 1, 0, 1, 2};

int recur(int x)
{
	if(x<=4)
		return v[x];
	if(x%2)
		return 0;
	if(recur(x/2)==1)
		return 2;
	else
		return 1;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(k%2==0)
		{
			if(a[i]<=2)
				nim^=a[i];
			else
				nim^=(a[i]%2==0);
		}
		else
		{
			nim^=recur(a[i]);
		}
	}
	if(nim)
		cout<<"Kevin";
	else
		cout<<"Nicky";
	return 0;
}