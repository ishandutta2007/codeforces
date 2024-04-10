#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1009;
int f[N],sz[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
basic_string<int>a;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,d,i,j,k,l,cnt=1;
	cin>>n>>d;
	for(i=1;i<=n;++i)f[i]=i,sz[i]=1;
	for(i=1;i<=d;++i){
		cin>>j>>k;
		if(j=gf(j),k=gf(k),j==k)++cnt;
		else{
			f[j]=k,sz[k]+=sz[j];
		}a={};
		for(j=1;j<=n;++j)if(f[j]==j)a+=sz[j];
		sort(begin(a),end(a),greater<int>());
		l=a.size(),k=0;
		for(j=0;j<l&&j<cnt;++j)k+=a[j];
		cout<<k-1<<'\n'; 
	}
	return 0;
}