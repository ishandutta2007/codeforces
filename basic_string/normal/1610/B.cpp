#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],n;
bool work(int x){
	int l=1,r=n;
	while(1){
		if(l>r)return 1;
		if(a[l]==x){++l;continue;}
		if(a[r]==x){--r;continue;}
		if(a[l]!=a[r])return 0;
		++l,--r;
	}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,m,l,r,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		for(l=1,r=n;l<=r;++l,--r)if(a[l]^a[r]){
			j=a[l],k=a[r];
			goto gg;
		}
		cout<<"YES\n";
		continue;
		gg:;
		if(work(j)||work(k))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}