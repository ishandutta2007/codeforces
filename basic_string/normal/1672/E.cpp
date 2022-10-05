#include<bits/stdc++.h>
using namespace std;
enum{N=2009};

int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,l=1,r=5e6,m,x,ans;
	cin>>n;
	while(l<=r){
		m=l+r>>1;
		cout<<"? "<<m<<endl;
		cin>>x;
		if(x==1)r=m-1;
		else l=m+1;
	}
	ans=l;
	for(int i=2;i<=n;++i){
		cout<<"? "<<l/i<<endl;
		cin>>x;
		if(x==i)ans=min(ans,l/i*x);
	}
	cout<<"! "<<ans<<endl;
}/*
8+8+8
9+9+8
*/
//l