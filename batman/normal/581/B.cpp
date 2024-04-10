#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (301*1000)
ll n,a[N],ans[N],maxi;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=n-1;i>=0;i--)
    {
    	ans[i]=max(0ll,maxi-a[i]+1);
    	maxi=max(maxi,a[i]);
	}
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    
    
	return 0;
}