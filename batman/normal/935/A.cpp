#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)



int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,ans=0;cin>>n;
	for(int i=1;i<n;i++)
		if((n-i)%i==0)
			ans++;
	cout<<ans<<"\n";
	
	return 0;
}