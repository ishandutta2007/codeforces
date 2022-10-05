#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
char s[N];
bool b[N];
long long ans;
int a[N];
void solve(int l,int r){
	if(l==r){
		if(b[l])++ans;
		return;
	}
	int m=l+r>>1,i,j=0,k=0,u=0,u2=0,lu,lv;
	bool f=0;
	solve(l,m),solve(m+1,r);
	long long now=0,nowu=0,aans=ans;
	for(i=m+1;i<=r;++i){
		if(b[i])++j;
		else{
			if(!f)f=1;
			j=0;
		}
		if(!f)u=j;
		k=max(k,j),a[i]=k,now+=k;
	}
	lu=lv=m+1,f=0,k=j=0;
	for(i=m;i>=l;--i){
		if(b[i])++j;
		else{
			if(!f)f=1;
			j=0;
		}
		if(!f)u2=j;
		k=max(k,j);
		while(lu<=r&&min(lu-m,u)+u2>a[lu])nowu+=min(lu-m,u),now-=a[lu],a[lu]=-1,++lu;
		while(lv<=r){
			if(a[lv]==-1){
				if(k>min(lv-m,u)+u2)nowu-=min(lv-m,u),++lv;
				else break;
			}else{
				if(k>a[lv])now-=a[lv],++lv;
				else break;
			}
		}
		ans+=now+nowu+max(0,lu-lv)*1ll*u2+(lv-m-1)*1ll*k;
	}
}
int main(){
	int n,i,j;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;++i)if(s[i]=='1')b[i]=1;else b[i]=0;
	solve(1,n);
	printf("%lld",ans);
	return 0;
}