#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
int n,m,a[102],b[102],pd[402];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],pd[a[i]]=1;
	cin>>m;
	for(int i=1;i<=m;i++)cin>>b[i],pd[b[i]]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!pd[a[i]+b[j]])
				cout<<a[i]<<" "<<b[j],exit(0);
	return 0;
}