#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
int q,n,x[203]; 
int main()
{
	cin>>q;
	for(int l=0;l<q;l++){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(n==1){cout<<"YES\n";continue;}
		int tpd=0;
		for(int i=1;i<=n;i++){
			int cnt=1,p=i,pd=1;
			while(cnt<n){
				int las=(p==1?n:p-1);
				if(x[p]-x[las]!=1){pd=0;break;}
				cnt++,p++;
				if(p>n)p=1;
			}
			if(pd){tpd=1;break;}
		}
		for(int i=1;i<=n;i++){
			int cnt=1,p=i,pd=1;
			while(cnt<n){
				int las=(p==n?1:p+1);
				if(x[p]-x[las]!=1){pd=0;break;}
				cnt++,p--;
				if(p<1)p=n;
			}
			if(pd){tpd=1;break;}
		}
		if(tpd)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}