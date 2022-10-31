#include<bits/stdc++.h>
#define N 100100
using namespace std;
long long s[N],g[N],sg[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) cin>>s[i];
	sort(s,s+n);
	for(int i=0;i+1<n;i++){
		g[i]=s[i+1]-s[i];
	}
	sort(g,g+n-1);
	sg[0]=0;
	for(int i=0;i<n-1;i++){
		sg[i+1]=sg[i]+g[i];
	}
	int q;
	scanf("%d",&q);
	while(q--){
		long long l,r;
		cin>>l>>r;
		r=r-l+1;
		int pos=lower_bound(g,g+n-1,r)-g;
		printf("%lld\n",(n-pos)*r+sg[pos]);
	}
	return 0;
}