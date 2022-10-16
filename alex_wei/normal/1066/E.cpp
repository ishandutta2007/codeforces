#include<bits/stdc++.h>
using namespace std;
long long n,m,po[200005],sum,mod=998244353,ans;
string a,b; 
int main()
{
	po[0]=1;
	for(int i=1;i<200002;i++)po[i]=(po[i-1]*2)%mod;
	cin>>n>>m>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=b.size()-1;i>=0;i--){
		sum+=b[i]=='1';
		if(i<a.size()&&a[i]=='1')ans=(ans+sum*po[i])%mod;
	}
	cout<<ans;
	return 0;
}