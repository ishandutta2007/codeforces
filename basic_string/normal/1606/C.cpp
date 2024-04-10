#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+3;
int a[99],pw[99];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,k,i;
	ll now;
	cin>>T;
	pw[0]=1;
	for(int i=1;i<10;++i)pw[i]=pw[i-1]*10;
	while(T--){
		cin>>n>>k;
		for(i=0;i<n;++i)cin>>a[i];
		now=0;
		for(i=1;i<n;++i){
			if(now+=pw[a[i]-a[i-1]]-1,now>k){
				now-=pw[a[i]-a[i-1]]-1;
				cout<<k-now+1;
				for(i=a[i-1];i;--i)cout<<9;
				goto gg;
			}
		}
		cout<<k-now+1;
		for(i=a[n-1];i;--i)cout<<9;
		gg:;cout<<'\n';
	}
	return 0;
}