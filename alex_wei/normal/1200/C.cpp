#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll n,m,q,s1,s2,e1,e2,d;
int main()
{
	cin>>n>>m>>q,d=gcd(n,m),n/=d,m/=d;
	for(int i=1;i<=q;i++){
		cin>>s1>>s2>>e1>>e2;
		if(s1==1)s2=(s2-1)/n;
		else s2=(s2-1)/m;
		if(e1==1)e2=(e2-1)/n;
		else e2=(e2-1)/m;
		if(s2!=e2)cout<<"NO";
		else cout<<"YES"; 
		cout<<endl;
	}
	return 0;
}