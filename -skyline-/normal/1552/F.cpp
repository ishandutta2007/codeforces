#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  998244353
using namespace std;
int n,x[200005],y[200005],s[200005];
ll ans,S[200005],f[200005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",x+i,y+i,s+i);
	for(int i=1;i<=n;++i){
		f[i]=x[i]-y[i];
		int o=0;
		for(int j=17;j>=0;--j){
			int O=o+(1<<j);
			if(O<=n&&x[O]<y[i])o=O;
		}
		f[i]+=S[i-1]-S[o];
		f[i]=(f[i]%orz+orz)%orz;
		S[i]=(S[i-1]+f[i])%orz;
		if(s[i])ans=(ans+f[i])%orz;
	}
	ans=(ans+x[n]+1)%orz;
	ans=(ans%orz+orz)%orz;
	cout<<ans<<endl;
    return 0;
}