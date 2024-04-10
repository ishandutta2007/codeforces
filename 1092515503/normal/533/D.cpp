#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100100],d[100100],f[100100],g[100100],stk[100100],tp,res;
vector<ll>v;
int t[100100],m;
void ADD(int x,int y){x=lower_bound(v.begin(),v.end(),x)-v.begin()+1;while(x)t[x]=max(t[x],y),x-=x&-x;}
int SUM(int x){
	x=lower_bound(v.begin(),v.end(),x)-v.begin()+1;
	int ret=-1;
	while(x<=m)ret=max(ret,t[x]),x+=x&-x;
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	stk[tp=0]=0;
	for(int i=1;i<=n;i++){
		while(tp&&a[i]-a[f[stk[tp]]]>2ll*d[stk[tp]])tp--;
		f[i]=stk[tp];
		while(tp&&2ll*d[stk[tp]]+a[f[stk[tp]]]<=2ll*d[i]+a[f[i]])tp--;
		stk[++tp]=i;
	}
	stk[tp=0]=n+1;
	for(int i=n;i>=1;i--){
		while(tp&&a[g[stk[tp]]]-a[i]>2ll*d[stk[tp]])tp--;
		g[i]=stk[tp];
		while(tp&&a[g[stk[tp]]]-2ll*d[stk[tp]]>=a[g[i]]-2ll*d[i])tp--;
		stk[++tp]=i;
	}
//	for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",g[i]);puts("");
	for(int i=1;i<=n;i++)if(a[g[i]]-a[f[i]]<=2ll*d[i]){puts("0");return 0;}
	for(int i=1;i<=n;i++)if(a[i]-a[f[i]]<2ll*d[i])v.push_back(2ll*d[i]+a[f[i]]);
	sort(v.begin(),v.end()),v.resize(m=unique(v.begin(),v.end())-v.begin()),memset(t,-1,sizeof(t));
	res=a[n+1];
	for(int i=1;i<=n;i++)res=min(res,a[g[i]]-a[f[i]]);//replacing an ordinary column
	for(int i=1;i<=n;i++){//stand between two ordinary columns
		if(a[g[i]]-a[i]<2ll*d[i]){
			int tmp=SUM(a[g[i]]-2ll*d[i]);
			if(tmp!=-1)res=min(res,a[i]-tmp);
		}
		if(a[i]-a[f[i]]<2ll*d[i])ADD(2ll*d[i]+a[f[i]],a[i]);
	}
	for(int i=1;i<=n;i++){//stand between an ordinary column and a bearing column
		if(f[i]==0&&a[g[i]]-a[i]<2ll*d[i])res=min(res,a[i]);
		if(g[i]==n+1&&a[i]-a[f[i]]<2ll*d[i])res=min(res,a[n+1]-a[i]);
	}
	printf("%.1lf",res*0.5);
	return 0;
}