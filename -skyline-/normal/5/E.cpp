#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
using namespace std;
int n,m,res,cnt,in[1000005],l[1000005],a[1000005],st[1000005],k,d[1000005],st2[1000005];
ll ans;
void solve(){
	if(cnt==1){
		for(int i=1;i<=n;++i)d[i]=0;
	}
	k=0;
	for(int i=1;i<n;++i){
		while(k&&st[k]<=a[i])--k;
		if(k)++ans;
		if(cnt==1&&k==1)++d[i];
		st[++k]=a[i];
	}
	k=0;
	for(int i=n;i>1;--i){
		while(k&&st[k]<a[i])--k;
		if(k)++ans;
		if(cnt==1&&(k==1||(k==2&&st[k]==a[i]))&&d[i])--ans;
		if(k&&st[k]==a[i])ans+=st2[k],++st2[k];
		else st[++k]=a[i],st2[k]=1;
	}
}
int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;++i)scanf("%d",in+i),res=max(res,in[i]);
	for(int i=1;i<=m;++i)if(in[i]==res)l[++cnt]=i;
	ans+=cnt*(cnt-1ll)/2ll;
	for(int i=1;i<cnt;++i){
		if(l[i]<l[i+1]){
			n=0;
			a[++n]=res;
			for(int j=l[i]+1;j<l[i+1];++j)a[++n]=in[j];
			a[++n]=res;
			solve();
		}
	}
	if(l[1]>1||l[cnt]<m){
		n=0;
		a[++n]=res;
		for(int i=l[cnt]+1;i<=m;++i)a[++n]=in[i];
		for(int i=1;i<l[1];++i)a[++n]=in[i];
		a[++n]=res;
		solve();
	}
	printf("%I64d\n",ans);
	return 0;
}