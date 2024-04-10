#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=20;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<(1<<n);i++)
	{
		int cur=0;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
				cur+=a[j];
			else
				cur-=a[j];
		}
		cur=abs(cur);
		if(cur%360==0)
		{
			cout<<"YES";
			return 0;
		}
	}	
	cout<<"NO";
	return 0;
}