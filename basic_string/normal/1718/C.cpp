#include<bits/stdc++.h>
using namespace std;
using ll=long long;
enum{N=200009};
int a[N],p[13],w[13];
ll f[13][N];
multiset<ll>st;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,q,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>q;st={};
		int m=n,t=0;
		for(i=2;i<=m;++i)if(m%i==0){
			w[++t]=n/i,p[t]=n/i;
			do m/=i;while(m%i==0);
		}
		for(i=1;i<=t;++i)for(j=0;j<w[i];++j)f[i][j]=0;
		for(i=1;i<=n;++i){
			cin>>a[i];
			for(j=1;j<=t;++j)f[j][i%w[j]]+=a[i];
		}
		for(i=1;i<=t;++i){
			for(j=0;j<w[i];++j)st.insert(f[i][j]*p[i]);
		}
		cout<<*st.rbegin()<<'\n';
		while(q--){
			cin>>i>>j;
			for(k=1;k<=t;++k){
				st.erase(st.find(f[k][i%w[k]]*p[k]));
				f[k][i%w[k]]+=j-a[i];
				st.insert(f[k][i%w[k]]*p[k]);
			}a[i]=j;
			cout<<*st.rbegin()<<'\n';
		}
	}
}