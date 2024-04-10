//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;
int T,n,m,a[N+1],b[N+1],ans,nn;
int gcd(int x,int y){return (y%x==0)?x:gcd(y%x,x);}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);n=unique(a+1,a+n+1)-a-1;
	if(n==1){
		for(int i=1;i<=m;i++){
			cin>>b[i];
			cout<<a[1]+b[i]<<' ';
		}
		cout<<'\n';
		return 0;
	}
	nn=a[n]-a[n-1];
	for(int i=n-1;i>1;i--){
		nn=gcd(nn,a[i]-a[i-1]);
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		cout<<gcd(nn,a[1]+b[i])<<' ';
	}
	cout<<'\n';
    return 0;
}
/*

*/