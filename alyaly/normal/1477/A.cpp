#include<bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;
int T,n,K,a[N+1],nd,ffl;
int gcd(int x,int y){return (y%x==0)?x:gcd(y%x,x);}
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>K;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);nd=a[2]-a[1];
		for(int i=3;i<=n;i++){
			nd=gcd(nd,a[i]-a[i-1]);
		}
		ffl=0;
		for(int i=1;i<=n;i++){
			if(abs(K-a[i])%nd==0){
				ffl=1;
				break;
			}
		}
		if(ffl)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}