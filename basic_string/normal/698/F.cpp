#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=1e6+9;
int jc[N],a[N],ct[N],to[N],fr[N],w[N],w2[N],p[N],mx[N];
bool b[N];
#define gg {cout<<0;return 0;}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k,ans=1;
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i],p[i]=1;
	for(jc[0]=i=1;i<=n;++i)jc[i]=jc[i-1]*1ll*i%P;
	ct[1]=1;
	for(i=2;i<=n;++i)if(!b[i]){
		ct[i]=n/i;
		for(j=i;j<=n;j+=i){
			b[j]=1;
			p[j]*=i,mx[j]=i;
		}
	}
	mx[1]=1;
	for(i=1;i<=n;++i)if(a[i]){
		j=mx[i],k=mx[a[i]];
		if(p[i]/j!=p[a[i]]/k)gg
		if(ct[j]^ct[k])gg
		if(to[j]&&to[j]!=k)gg
		if(fr[k]&&fr[k]!=j)gg
		to[j]=k,fr[k]=j;
	}else ++w2[p[i]];
	for(i=1;i<=n;++i)if(!to[i])++w[ct[i]];
	for(i=1;i<=n;++i)ans=ans*1ll*jc[w[i]]%P*jc[w2[i]]%P;
	cout<<ans;
	return 0;
}