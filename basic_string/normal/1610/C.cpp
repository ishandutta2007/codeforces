#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],b[N],n;
bool chk(int x){
	int i,t=0;
	for(i=1;i<=n;++i){
		if(t<=b[i]&&t+1+a[i]>=x)++t;
	}
	return t>=x;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,m,l,r,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i]>>b[i];
		l=1,r=n;
		while(l<=r){
			m=l+r>>1;
			if(chk(m))l=m+1;
			else r=m-1;
		}
		cout<<r<<'\n';
	}
	return 0;
}