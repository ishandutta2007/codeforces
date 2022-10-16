#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,m,ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(m==0||n==0)puts("0");
		else{
			int rem=n-m,div=m;
			ll k=rem/(div+1),l=rem%(div+1);
			cout<<n*(n+1)/2-(div+1-l)*k*(k+1)/2-l*(k+1)*(k+2)/2<<endl;
		}
	}
    return 0;
}