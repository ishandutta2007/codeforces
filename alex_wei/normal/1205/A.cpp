#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
ll n,sum,p=0;
int main()
{
	cin>>n;
	sum=(1+n)*n/2*n;
	if(n%2)cout<<"YES\n";
	else cout<<"NO\n",exit(0);
	for(int i=1;i<=n;i++){
		if(i%2)p++,cout<<p<<" ";
		else p+=3,cout<<p<<" ";
	}
	p=-1;
	for(int i=1;i<=n;i++){
		if(i%2)p+=3,cout<<p<<" "; 
		else p++,cout<<p<<" ";
	}
	return 0;
}