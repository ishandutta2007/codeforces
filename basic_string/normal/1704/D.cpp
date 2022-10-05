#include<bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k,c0,p0,c1,p1;
	unsigned long long u,w,w0,w1;
	for(cin>>T;T--;){
		cin>>n>>m;c0=p0=c1=p1=w0=w1=0;
		for(i=1;i<=n;++i){
			w=0;
			for(j=1;j<=m;++j)cin>>u,w+=j*u;
			if(!c0)++c0,p0=i,w0=w;
			else if(w==w0)++c0;
			else if(!c1)++c1,p1=i,w1=w;
			else if(w==w1)++c1;
		}
		if(c0==1)cout<<p0<<' '<<w0-w1<<'\n';
		else cout<<p1<<' '<<w1-w0<<'\n';
	}
}