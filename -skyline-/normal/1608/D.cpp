#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  998244353
using namespace std;
int n,cnt,lv,lm,rm,L,R;
bool ok;
ll jc[100005],njc[100005],ans;
 
ll fp(ll x,ll k){
	ll a=1;
	while(k){
		if(k&1)(a*=x)%=orz;
		(k>>=1),(x*=x)%=orz;
	}
	return a;
}
ll c(int x,int y){return jc[x]*njc[y]%orz*njc[x-y]%orz;}
int main(){
	scanf("%d",&n);
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%orz;
	njc[n]=fp(jc[n],orz-2);
	for(int i=n;i;--i)njc[i-1]=njc[i]*i%orz;
	for(int i=1;i<=n;++i){
		char l,r;
		scanf(" %c%c",&l,&r);
		if(l=='?'&&r=='?')++cnt;
		else if(l=='?'||r=='?'){
			if(l=='W'||r=='W')++lm;
			else ++rm;
		}
		else if(l==r){
			if(l=='W')++lv;
			else --lv;
			ok=1;
		}
		else{
			if(l=='W')++L;
			else ++R;
		}
	}
	lm+=cnt;
	rm+=cnt;
	for(int i=0;i<=lm;++i){
		int k=lv+i;
		if(k>=0&&k<=rm)(ans+=c(lm,i)*c(rm,k))%=orz;
	}
	if(!ok){
		ans=(ans-fp(2,cnt))%orz;
		if(cnt==n)(ans+=2)%=orz;
		else if(L==0&&lm==cnt)(ans+=1)%=orz;
		else if(R==0&&rm==cnt)(ans+=1)%=orz;
	}
	ans=(ans%orz+orz)%orz;
	printf("%I64d\n",ans);
    return 0;
}