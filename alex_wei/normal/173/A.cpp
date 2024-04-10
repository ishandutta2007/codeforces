#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int a[1000002],b[1000002],n,l,r,los[128][128],cyc;
string s,t;
int main()
{
	cin>>n>>s>>t;
	cyc=s.size()*t.size()/gcd(s.size(),t.size());
	los['R']['P']=1,los['P']['S']=1,los['S']['R']=1;
	for(int i=1;i<=cyc;i++){
		a[i]=a[i-1]+los[s[l]][t[r]],b[i]=b[i-1]+los[t[r]][s[l]];
		l=(l+1)%s.size(),r=(r+1)%t.size();
	}
	cout<<n/cyc*a[cyc]+a[n%cyc]<<" "<<n/cyc*b[cyc]+b[n%cyc];
	return 0;
}