#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
int n,a[150003],w[150003],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(!w[a[i]-1]&&a[i]-1>0)w[a[i]-1]=1;
		else if(!w[a[i]])w[a[i]]=1;
		else w[a[i]+1]=1;
	}
	for(int i=1;i<=150002;i++)
		ans+=w[i];
	cout<<ans;
	return 0;
}