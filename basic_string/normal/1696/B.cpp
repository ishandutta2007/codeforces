#include<bits/stdc++.h>
using namespace std;
int a[100009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		int l=0,r=n+1;
		for(i=1;i<=n;++i)if(a[i]!=0)l=i;
		for(i=n;i;--i)if(a[i]!=0)r=i;
		swap(l,r);
		if(!r)cout<<0<<'\n';
		else{
			for(i=l;i<=r;++i)if(!a[i]){cout<<2<<'\n';goto gg;}
			cout<<1<<'\n';
			gg:;
		}
	}
}