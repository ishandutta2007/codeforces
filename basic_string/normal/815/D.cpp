#include<bits/stdc++.h>
using namespace std;
enum{N=500009};
vector<pair<int,int>>v[N];
int m[N];
long long s[N],w;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,a,b,c,i,j,k;
	for(cin>>n>>a>>b>>c;n--;)cin>>i>>j>>k,v[i].push_back({j,k}),m[j]=max(m[j],k);
	for(i=b;~i;--i)m[i]=max(m[i],m[i+1]);
	for(i=1;i<=b;++i)s[i]=s[i-1]+m[i];
	for(j=k=0,i=b;a;w+=(b-i)*1ll*(c-k)+(i-j)*1ll*c-s[i]+s[j],--a){
		for(auto o:v[a])j=max(j,o.first),k=max(k,o.second);
		for(i=max(i,j);i>j&&m[i]<k;--i);
	}cout<<w;
	return 0;
}