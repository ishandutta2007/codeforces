#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,m,a[100005],f[100005],p,q,ans;
int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int x;
		scanf("%d",&x);
		if(x!=a[n])a[++n]=x;
	}
	if(n==1){
		printf("1\n");
		return 0;
	}
	for(int i=0;i<=m;++i)f[i]=-m;
	f[a[1]]=0;
	p=a[1];
	for(int i=3;i<=n;++i){
		int o=(a[i]==p)?q:p;
		f[a[i-1]]=max(f[a[i]]+1,f[o]);
		if(f[a[i-1]]>f[p])q=p,p=a[i-1];
		else if(f[a[i-1]]>f[q])q=a[i-1];
	}
	for(int i=1;i<=m;++i)ans=max(ans,f[i]);
	printf("%d\n",n-ans);
    return 0;
}