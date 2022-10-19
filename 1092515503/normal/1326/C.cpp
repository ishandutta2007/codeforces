#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353; 
int n,k,r1,las,r2=1;
bool p[200100];
signed main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++)r1+=(n-i+1);
	for(int i=1,x;i<=n;i++){
		cin>>x;
		p[i]=(x>=(n-k+1));
	}
	cout<<r1<<" ";
	for(int i=1;i<=n;i++){
		if(!p[i])continue;
		if(las)(r2*=(i-las))%=mod;
		las=i;
	}
	cout<<r2<<endl;
	return 0;
}