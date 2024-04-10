#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=9e18;
int T,n;
ll X[100100],Y[100100],Z[100100],a,b,c;
bool che(ll d){
	ll mn[4]={inf,inf,inf,inf},mx[4]={-inf,-inf,-inf,-inf};
	for(int i=1;i<=n;i++){
		mn[0]=min(mn[0],X[i]+Y[i]+Z[i]+d);
		mx[0]=max(mx[0],X[i]+Y[i]+Z[i]-d);
		mn[1]=min(mn[1],X[i]+Y[i]-Z[i]+d);
		mx[1]=max(mx[1],X[i]+Y[i]-Z[i]-d);
		mn[2]=min(mn[2],X[i]-Y[i]+Z[i]+d);
		mx[2]=max(mx[2],X[i]-Y[i]+Z[i]-d);
		mn[3]=min(mn[3],-X[i]+Y[i]+Z[i]+d);
		mx[3]=max(mx[3],-X[i]+Y[i]+Z[i]-d);
	}
	for(int i=0;i<=3;i++)if(mx[i]>mn[i])return false;
	ll MN[4],MX[4];bool ok;
	ok=true;for(int i=0;i<=3;i++){
		MN[i]=mx[i],MX[i]=mn[i];
		if(MN[i]&1)MN[i]++;if(MX[i]&1)MX[i]--;
		if(MN[i]>MX[i])ok=false;
	}
	if(MN[0]>MX[1]+MX[2]+MX[3])ok=false;
	if(MX[0]<MN[1]+MN[2]+MN[3])ok=false;
	if(ok){
//		for(int i=0;i<=3;i++)printf("[%lld,%lld]",MN[i],MX[i]);puts("");
		a=MN[1],b=MN[2],c=MN[3];
		if(a+b+c>=MN[0])return true;
		a=MX[1];if(a+b+c>=MN[0]){a+=MN[0]-a-b-c;return true;}
		b=MX[2];if(a+b+c>=MN[0]){b+=MN[0]-a-b-c;return true;}
		c=MX[3];if(a+b+c>=MN[0]){c+=MN[0]-a-b-c;return true;}
	}
	ok=true;for(int i=0;i<=3;i++){
		MN[i]=mx[i],MX[i]=mn[i];
		if(!(MN[i]&1))MN[i]++;if(!(MX[i]&1))MX[i]--;
		if(MN[i]>MX[i])ok=false;
	}
	if(MN[0]>MX[1]+MX[2]+MX[3])ok=false;
	if(MX[0]<MN[1]+MN[2]+MN[3])ok=false;
	if(ok){
		a=MN[1],b=MN[2],c=MN[3];
		if(a+b+c>=MN[0])return true;
		a=MX[1];if(a+b+c>=MN[0]){a+=MN[0]-a-b-c;return true;}
		b=MX[2];if(a+b+c>=MN[0]){b+=MN[0]-a-b-c;return true;}
		c=MX[3];if(a+b+c>=MN[0]){c+=MN[0]-a-b-c;return true;}
	}
	return false;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&X[i],&Y[i],&Z[i]);
		ll l=0,r=3e18;
		while(l<r){
			ll mid=(l+r)>>1;
			if(che(mid))r=mid;
			else l=mid+1;
		}
//		printf("%lld\n",l);
		che(l);
//		printf("%lld %lld %lld\n",a,b,c);
		printf("%lld %lld %lld\n",(a+b)>>1,(a+c)>>1,(b+c)>>1);		
	}
	return 0;
} 
/*
1
2
-618233948963987897 -291725525979727364 -186770225069589223
104379375545472276 -140802889285193371 404452083251857876

219100486708870876
238632107215391794
*/