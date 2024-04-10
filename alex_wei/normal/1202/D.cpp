#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
ll t,n,p[50000];
int main()
{
	t=read();
	for(ll i=1;i<=t;i++){
		memset(p,0,sizeof(p));
		n=read();
		ll k=0,r=n;
		for(ll j=sqrt(n)+3;j>1;j--){
			ll mi=j*(j-1)/2;
			if(n>=mi)k=max(k,j),p[j]=n/mi,n%=mi;
		}
		cout<<"1";
		for(int j=1;j<=k;j++){
			cout<<'3';
			for(int q=1;q<=p[j];q++)
				cout<<'7';
		}
		cout<<endl;
	}
	return 0;
}