#include<bits/stdc++.h>
using namespace std;
enum{N=1000009,M=78579};
using ll=long long;
int f[N][13],c[N][13],len[N],p[M],id[N];
ll a[M];
bool b[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int m,i,j,l,o,t=0,k2;
	ll k,u;
	for(i=2;i<N;++i)if(!b[i]){
		p[++t]=i,id[i]=t;
		for(j=i;j<N;j+=i){
			b[j]=1,l=0,o=j;
			do o/=i,++l;while(o%i==0);
			f[j][++len[j]]=t,c[j][len[j]]=l;
		}
	}
	cin>>m;
	while(m--)cin>>i>>k,a[id[i]]=k;
	cin>>k,k2=min(k,19ll),k-=k2;
	while(k2--){
		for(i=1;i<=t;++i)if(a[i]){
			--a[i],j=p[i]-1;
			for(l=len[j];l;--l)a[f[j][l]]+=c[j][l];
		}
	}
	for(i=t;i;--i)if(a[i]){
		u=min(a[i],k),a[i]-=u,j=p[i]-1;
		for(l=len[j];l;--l)a[f[j][l]]+=c[j][l]*u;
	}
	for(i=1,j=0;i<=t;++i)if(a[i])++j;
	cout<<j<<'\n';
	for(i=1;i<=t;++i)if(a[i])cout<<p[i]<<' '<<a[i]<<'\n';
}