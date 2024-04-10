#include<bits/stdc++.h>
using namespace std;
using ll=long long;
enum{N=1000009};
ll sz[N],d[N];
int a[N],b[N],c[N][2];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,id,o;
	ll k,w,s=0;
	cin>>n>>k;
	for(i=2;i<=n;++i)cin>>j>>w,d[i]=d[j]^w;
	for(i=61;~i;--i){
		memset(sz,0,n*8+8),memset(c,0,n*8+8),id=w=0;
		for(j=1;j<=n;++j){
			int&p=c[a[j]][d[j]>>i&1];
			if(!p)p=++id;
			++sz[a[j]=p];
		}
		for(j=1;j<=n;++j)w+=sz[c[b[j]][d[j]>>i&1]];
		if(o=0,w<k)k-=w,s|=1ll<<i,o=1;
		for(j=1;j<=n;++j)b[j]=c[b[j]][(d[j]>>i&1)^o];
	}
	cout<<s;
	return 0;
}