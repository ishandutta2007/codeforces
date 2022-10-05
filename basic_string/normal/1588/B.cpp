#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
int qry(int r){
	cout<<"? "<<1<<' '<<r<<endl;
	ll x;
	cin>>x;
	return x;
}
signed main(){//ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k,l,r,m;
	ll tot;
	for(cin>>T;T--;){
		cin>>n;
		tot=qry(n);
		l=1,r=n;
		while(l<=r){
			m=l+r>>1;
			if(qry(m)==tot)r=m-1;
			else l=m+1;
		}
		//k=l
		k=l;
		i=tot-qry(l-1);
		j=k-i;
		tot-=(1ll+i)*i/2;
		l=1,r=n;
		while(l<=r){
			m=l+r>>1;
			if((1ll+m)*m/2<tot)l=m+1;
			else r=m-1;
		}
		i=j-l-1;
		cout<<"! "<<i<<' '<<j<<' '<<k<<endl;
	}
	return 0;
}/*
1 2 3 4 5 6 7 8
i=2 j=6 k=7
1 5 4 3 2 7 6 8*/
//0 0 1 3 6 6 7 7
/*
2 1 5 4 3
21 543
1 1+2

+0+1 +0+1+2*/