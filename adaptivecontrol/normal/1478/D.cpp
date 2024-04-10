#include<bits/stdc++.h>
using namespace std;
int T,n;
long long fb(long long a){if(a>0)return a;else return -a;}
int main(){
	cin>>T;
	while(T--){
		long long nwgcd=0,x[2],k;
		cin>>n>>k>>x[0];
		for(int i=1;i<n;i++){
			scanf("%lld",x+1);
			nwgcd=__gcd(nwgcd,fb(x[0]-x[1]));
		}
		if(fb(x[0]-k)%nwgcd)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}