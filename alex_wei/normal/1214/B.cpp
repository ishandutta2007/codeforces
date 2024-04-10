#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll b,g,n,ans;
int main()
{
	cin>>b>>g>>n;
	for(int i=0;i<=min(n,b);i++)
		if(g>=n-i)ans++;
	cout<<ans;
    return 0;
}