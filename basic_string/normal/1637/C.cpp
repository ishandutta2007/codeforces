#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
int a[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	long long sum=0;
	for(cin>>T;T--;){
		cin>>n;sum=0;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=2;i<n;++i)sum+=a[i];
		bool fl=0;
		for(i=2;i<n;++i)if(a[i]&1)++sum;
		for(i=2;i<n;++i)if(a[i]!=1)fl=1;
		if(!fl){cout<<-1<<'\n';continue;}
		if(n==3&&(a[2]&1)){cout<<-1<<'\n';continue;}
		if(sum&1)++sum;
		cout<<sum/2<<'\n';
	}
	return 0;
}