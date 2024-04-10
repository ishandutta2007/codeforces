#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k,l;
	long long ans=0,w;
	for(cin>>T;T--;){
		cin>>n>>m;ans=0;w=1e18;
		for(i=1;i<=n;++i)cin>>a[i],a[i]+=i-1;
		sort(a+1,a+n+1,greater<int>());
	//	cout<<ans+(1ll+(n-m))*(n-m)/2<<'\n';
		for(i=n;;--i){
			if(i<=m){
				w=min(w,ans-((n-i)-1ll)*(n-i)/2);
			}
			if(!i)break;
			ans+=a[i];
		}cout<<w<<'\n';
	}
}/*
5
11
13
8*/