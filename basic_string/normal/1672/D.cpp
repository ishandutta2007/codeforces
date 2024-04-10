#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],b[N],c[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i],c[i]=0;
		for(i=1;i<=n;++i)cin>>b[i];
		b[n+1]=0;
		k=n;
		for(i=n;i;--i){
			if(b[i]==b[i+1]){
				++c[b[i]];
				continue;
			}
			while(b[i]!=a[k]){
				if(!c[a[k]]){
					cout<<"NO\n";
					goto gg;
				}
				--c[a[k]];
				--k;
			}
			--k;
		}
		cout<<"YES\n";
		gg:;
	}
}