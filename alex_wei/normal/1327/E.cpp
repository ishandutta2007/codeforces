#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const ll mod=998244353;
const int N=2e5+5;
 
ll n,pw[N];

int main(){
	cin>>n,pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*10%mod;
	for(int i=1;i<=n;i++){
		if(i==n)puts("10");
		else cout<<(pw[n-i]*18+(n-i-1)*pw[n-i-1]*81)%mod<<" ";
	}
	return 0;
}