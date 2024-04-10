#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int a[N],ans,n;
map<int,int>mp;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,i,j,k,l,now,tmp,n2;
	for(cin>>T;T--;){
		cin>>n;ans=1e9;n2=n;mp={};
		for(i=1;i<=n;++i)cin>>a[i],++mp[a[i]];
		n=unique(a+1,a+n+1)-a-1;
		for(i=1;i<=n;++i){
			l=a[i],k=i+1,now=0;
			while(k<=n){
				j=lower_bound(a+k+1,a+n+1,a[k]-l+a[k])-a;
				now+=j-k-1;
				k=j;
			}
			ans=min(ans,now+i-1+n2-n-mp[a[i]]+1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}