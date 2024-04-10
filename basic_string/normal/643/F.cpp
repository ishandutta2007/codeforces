#include<bits/stdc++.h>
using namespace std;
using ui=unsigned;
using ul=unsigned long long;
const int N=133;
ui c[N];
void get(ui&p,ui&w,ui x){
	while(x%2==0)x/=2,++p;
	w*=x;
}
void exgcd(ul a,ul b,ui&x,ui&y){b?(exgcd(b,a%b,y,x),y-=a/b*x):(x=1,y=0);}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	ui n,q,p,i,j,k,l,pl=0,pr=0,wl=1,wr=1,ans=0;
	cin>>n>>p>>q,p=min(p,n-1);
	for(i=c[0]=1;i<=p;++i){
		get(pl,wl,i),get(pr,wr,n-i+1);
		if(pr-pl<32)exgcd(wl,1ll<<32,j,k),c[i]=j*wr*(1u<<pr-pl);
	}
	for(i=1;i<=q;++i){
		for(j=k=0,l=1;j<=p;++j)k+=c[j]*(l*=i);
		ans^=k;
	}
	cout<<ans;
	return 0;
}