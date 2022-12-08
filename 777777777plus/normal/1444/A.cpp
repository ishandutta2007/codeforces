#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
ll p,q,b[100],a[100],c[100];

int main(){
	cin>>T;
	while(T--){
		cin>>p>>q;
		if(p%q)cout<<p<<endl;
		else{
			memset(b,0,sizeof(b));
			memset(c,0,sizeof(c));
			int t=0;
			for(ll i=2;i*i<=q;++i)
			if(q%i==0){
				a[++t]=i;
				while(q%i==0)q/=i,b[t]++;
			}
			if(q>1){
				a[++t]=q;
				b[t]=1;
			}
			ll mn=1e18,p1=p;
			for(int i=1;i<=t;++i){
				while(p%a[i]==0)p/=a[i],c[i]++;
				ll cnt=c[i]-b[i]+1;
				ll val=1;
				for(int j=1;j<=cnt;++j)val*=a[i];
				mn=min(mn,val);
			}
			cout<<p1/mn<<endl;
		}
	}
}