#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m[1500005],pre[1500005],suf[1500005],stc[1500005],top,G[1500005],val[1500005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>m[i];
	for(ll i=1;i<=n;i++){
		int K=1;
		pre[i]=pre[i-1]+m[i];
		while(top&&m[i]<stc[top]){
			pre[i]-=val[top]*(stc[top]-m[i]);
			K+=val[top];
			top--;
		}
		stc[++top]=m[i];
		val[top]=K;
	}
	top=0;
	for(ll i=n;i;i--){
		int K=1;
		suf[i]=suf[i+1]+m[i];
		while(top&&m[i]<stc[top]){
			suf[i]-=val[top]*(stc[top]-m[i]);
			K+=val[top];
			top--;
		}
		stc[++top]=m[i];
		val[top]=K;
	}
	ll ans=0,pos;
	for(int i=1;i<=n;i++)if(ans<suf[i]+pre[i]-m[i])ans=suf[i]+pre[i]-m[i],pos=i;
	ll tmp=1e9;
	for(int i=pos;i;i--){
		tmp=min(tmp,m[i]);
		G[i]=tmp;
	}
	tmp=1e9;
	for(int i=pos;i<=n;i++){
		tmp=min(tmp,m[i]);
		G[i]=tmp;
	}
	for(int i=1;i<=n;i++)printf("%lld ",G[i]);
    return 0;
}