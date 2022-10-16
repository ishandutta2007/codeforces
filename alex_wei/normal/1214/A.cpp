#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,d,e,ans=1e9; 
int main()
{
	cin>>n>>d>>e;
	for(int i=1;i<=10000&&n>=0;i++)
		ans=min(ans,n%d),n-=5*e;
	cout<<ans;
    return 0;
}