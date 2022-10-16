#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,c,f[1000005],ans;
int main()
{
	for(int i=1;i<=1e6;i++)
		for(int j=i;j<=1e6;j+=i)
			f[j]++;
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			for(int k=1;k<=c;k++)
				ans+=f[i*j*k];
	cout<<ans;
    return 0;
}