#include<bits/stdc++.h>
using namespace std;
int a[1000005],aa[1000005],b[1000005];
int vist[1000005];
int main(){
	int T=1;
	cin>>T;
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),aa[a[i]]=i;
		for(int i=1;i<=n;++i)scanf("%d",&b[i]),b[i]=aa[b[i]];
		for(int i=1;i<=n;++i)vist[i]=0;
		int A=0,B=0;
		for(int i=1;i<=n;++i)if(!vist[i]){
			int x=b[i],gs=1;
			vist[i]=1;
			while(x!=i){
				vist[x]=1;
				x=b[x];
				++gs;
			}
			A+=gs/2,B+=gs/2;
		}
		long long ans=0;
		for(int i=n;i>=n-B+1;--i)ans+=i;
		for(int i=1;i<=A;++i)ans-=i;
		cout<<2*ans<<endl;
	}
	return 0;
}