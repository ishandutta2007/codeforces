//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define P 998244353
using namespace std;
int T,n,m,K,a[200003],b[200003],ans,fl[200003],fa[200003];
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>K;ans=1;
		for(int i=1;i<=n;i++)cin>>a[i],fa[a[i]]=i;
		for(int i=1;i<=K;i++)cin>>b[i],fl[b[i]]=1;fl[0]=1;
		for(int i=1;i<=K;i++){
			int na=2;
			if(fl[a[fa[b[i]]-1]])na--;
			if(fl[a[fa[b[i]]+1]])na--;
			fl[b[i]]=0;
			ans=ans*na%P;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)fa[a[i]]=0,a[i]=0;
		for(int i=1;i<=K;i++)fl[b[i]]=0,b[i]=0;fl[0]=0;
	}
	return 0;
}
/*
10
5 3
1 2 3 4 5
2 4 3
1 1
1
1
*/