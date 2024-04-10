#include<bits/stdc++.h>
using namespace std;
string tmp[519];
int a[519],w[262149];
bool b[519];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,k,l,o,N;
	string s,u,ans;
	cin>>n>>s;
	N=1<<n;
	m=1<<(n/2);ans=s;
	for(i=0;i<N;i+=m){
		for(j=0;j<m;++j){
			tmp[j]="";
			for(k=0;k<m;++k)tmp[j]+=s[i+(j^k)];
		}
		for(j=0;j<m;++j)a[j]=j;
		sort(a,a+m,[](int x,int y){return tmp[x]<tmp[y];});
		for(j=1;j<m;++j)if(tmp[a[j]]==tmp[a[j-1]])w[a[j]+i]=w[a[j-1]+i];
		else w[a[j]+i]=w[a[j-1]+i]+1;
	}
	for(i=0;i<N;i+=m){
		for(j=0;j<m;++j)b[j]=1;
		for(k=0;k<N;k+=m){
			l=k^i;
			o=1e9;
			for(j=0;j<m;++j)if(b[j])o=min(o,w[l+j]);
			for(j=0;j<m;++j)if(w[l+j]>o)b[j]=0;
		}
		int z;
		for(j=0;j<m;++j)if(b[j]){z=j;break;}
		u="";
		for(k=0;k<N;k+=m){
			l=k^i;
			for(j=0;j<m;++j)u+=s[l+(z^j)];
		}
		if(u<ans)ans=u;
	}
	cout<<ans;
}