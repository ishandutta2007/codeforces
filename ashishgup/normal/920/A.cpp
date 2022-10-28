#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int a[N];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
    	int n, k;
    	cin>>n>>k;
    	int ans=0;	
    	for(int i=1;i<=k;i++)
    	{
    		cin>>a[i];
    	}
    	ans=max(a[1]-1+1, n-a[k]+1);
    	for(int i=1;i<=k-1;i++)
    	{
    		int x1=a[i];
    		int x2=a[i+1];
    		int cur=(x2-x1)/2 + 1;
    		ans=max(ans, cur);
    	}
    	cout<<ans<<endl;
    }
    return 0;
}