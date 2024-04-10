#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
ll n,a[100002],ans;
int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-n%2;i+=2){
		int k=abs(a[i]+1)+abs(a[i+1]+1),p=abs(a[i]-1)+abs(a[i+1]-1);
		ans+=min(k,p);
	}
	if(n%2)cout<<ans+abs(a[n]-1);
	else cout<<ans;
	return 0;
}