#include<bits/stdc++.h>
using namespace std;
enum{N=500009,M=23};
int c[M],p[M],a[N],l[N],s[N];
basic_string<int>e[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,q,i,j,x,y;
	for(cin>>n,i=1;i<=n;++i)cin>>a[i];
	for(cin>>q,i=1;i<=q;++i)cin>>l[i]>>j,e[j]+=i;
	for(i=1;i<=n;++i){
		for(j=19,x=a[i],y=i;~j;--j)if(x>>j&1){
			if(!c[j]){c[j]=x,p[j]=y;break;}
			if(y>p[j])swap(y,p[j]),swap(x,c[j]);
			x^=c[j];
		}
		for(int o:e[i])for(j=19;~j;--j)if(l[o]<=p[j])s[o]=max(s[o],s[o]^c[j]);
	}
	for(i=1;i<=q;++i)cout<<s[i]<<'\n';
	return 0;
}