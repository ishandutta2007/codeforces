#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
ll t,n,m,k,h[102];
int main()
{
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>k;
		for(int j=1;j<=n;j++)h[j]=read();
		int pd=1;
		for(int j=1;j<n;j++){
			ll minn=max((ll)0,h[j+1]-k);
			m+=max((ll)0,h[j]-minn);
			if(h[j]+m<h[j+1]-k){pd=0;break;}
			else m-=max((ll)0,h[j+1]-k-h[j]);
		}
		if(pd)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}