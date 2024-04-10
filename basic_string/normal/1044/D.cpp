#include<bits/stdc++.h>
using namespace std;
map<int,int>f,w;
int gf(int x){
	if(!f.count(x))return x;
	int i=gf(f[x]);
	return w[x]^=w[f[x]],f[x]=i;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int q,l=0,i,x,y,z,u,v;
	for(cin>>q;q--;){
		if(cin>>i>>x>>y,x^=l,y^=l,x>y)swap(x,y);
		if(--x,u=gf(x),v=gf(y),i==1){
			if(cin>>z,z^=l,u!=v)f[u]=v,w[u]=w[x]^w[y]^z;
		}else if(u!=v)cout<<"-1\n",l=1;else cout<<(l=w[x]^w[y])<<'\n';
	}
	return 0;
}