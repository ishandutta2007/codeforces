#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (201*1000)
ll n,a[N],ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n+1;i++)
	{
		if(a[i]==0 && a[i-1]==0 && i>1)
			ans--;
		while(a[i]==0 && a[i-1]==0 && i<=n)
			ans--,i++;
		
	}
	cout<<ans;
    return 0;
}