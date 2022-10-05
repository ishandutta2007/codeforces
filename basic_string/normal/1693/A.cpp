#include<bits/stdc++.h>
using namespace std;
const int N=200009;
long long a[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		long long sum=0,now,u;
		for(i=1;i<=n;++i)cin>>a[i],sum+=a[i];
		if(sum){
			cout<<"No\n";continue;
		}
		if(a[1]<0){cout<<"No\n";continue;}
		if(a[1]==0){
			for(i=2;i<=n;++i)if(a[i]){cout<<"No\n";goto gg;}
			cout<<"Yes\n";continue;
		}
		now=a[1];
		for(i=2;i<=n;++i){
			u=a[i]+now;
			if(u<0){cout<<"No\n";goto gg;}
			if(u==0){
				for(++i;i<=n;++i)if(a[i]){cout<<"No\n";goto gg;}
				cout<<"Yes\n";goto gg;
			}
			now=u;
		}
		cout<<"Yes\n";
		gg:;
	}
}