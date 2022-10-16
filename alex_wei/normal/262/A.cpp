#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a,ans;
int work(int x)
{
	int cnt=0;
	while(x){
		if(x%10==4||x%10==7)cnt++;
		x/=10;
	}
	return cnt;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a,ans+=work(a)<=k;
	cout<<ans<<endl;
	return 0;
}