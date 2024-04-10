#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9,B=333,P=998244353;
int a[N],f1[B],f2[B],g1[B],g2[B];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k,l,w,ans;
	for(cin>>T;T--;){
		cin>>n,ans=0;memset(f2,0,sizeof f2),memset(f1,0,sizeof f1),ans=0;
		for(i=1;i<=n;++i)cin>>a[i],f2[1]=1;
		for(i=n-1;i;--i){
			memset(g1,0,sizeof g1),memset(g2,0,sizeof g2);
			for(j=1;j<B;++j)if(k=f1[j]){
				l=j;
				w=(a[i]+l-1)/l,ans=(ans+(w-1ll)*k%P*i)%P;
				if(w<B)g2[w]+=k;else g1[a[i]/w]+=k;
			}
			for(j=1;j<B;++j)if(k=f2[j]){//cout<<i<<' '<<j<<' '<<k<<'!'<<'\n';
				l=a[i+1]/j,w=(a[i]+l-1)/l,ans=(ans+(w-1ll)*k%P*i)%P;//cout<<w<<'\n';
				
				if(w<B)g2[w]+=k;else g1[a[i]/w]+=k;
			}
			memcpy(f1,g1,sizeof f1),memcpy(f2,g2,sizeof f2);
			++f2[1];ans%=P;
		}
		cout<<ans<<'\n';
	}
	return 0;
}