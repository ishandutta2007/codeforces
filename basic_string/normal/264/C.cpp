#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+3;
int v[N],c[N];
ll f[N];
int main(){
	int n,q,i,a,b,s1,s2;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)scanf("%d",v+i);
	for(i=1;i<=n;++i)scanf("%d",c+i);
	while(q--){
		scanf("%d%d",&a,&b),s1=s2=0,memset(f,-9,sizeof(f)),f[0]=0;
		for(i=1;i<=n;++i){
			f[c[i]]=max(f[c[i]],max(f[c[i]]+a*1ll*v[i],f[c[i]==s1?s2:s1]+b*1ll*v[i]));
			if(f[c[i]]>f[s1]){
				if(c[i]!=s1)s2=s1;
				s1=c[i];
			}else if(f[c[i]]>f[s2]&&s1!=c[i])s2=c[i];
		}
		printf("%lld\n",f[s1]);
	}
	return 0;
}