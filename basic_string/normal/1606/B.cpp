#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k;
	long long a,b,ans,l,r,m;
	for(cin>>T;T--;){
		cin>>a>>b,ans=0;
		if(--a,a==0){cout<<0<<'\n';continue;}
		for(l=1;l<=b;l*=2){
			++ans,a-=l;
			if(a<=0){cout<<ans<<'\n';goto gg;}
		}
		ans+=a/b;
		if(a%b)++ans;
		cout<<ans<<'\n';
		gg:;
	}
	return 0;
}