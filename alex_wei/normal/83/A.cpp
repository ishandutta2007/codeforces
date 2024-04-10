#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,cnt,a[100005]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1||a[i]==a[i-1])cnt++;
		else ans+=(cnt+1)*cnt/2,cnt=1;
	}
	cout<<ans+cnt*(cnt+1)/2;
	return 0;
}