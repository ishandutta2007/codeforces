#include<bits/stdc++.h>
using namespace std;
int n,p[2002],ans=1e9,t;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<2*n;i++)
		t+=(s[i%n]=='T'),p[i]=(i==0?0:p[i-1])+(s[i%n]=='T');
	t/=2;
	for(int i=t;i<2*n;i++)
		ans=min(ans,t-p[i]+p[i-t]);
	cout<<ans;
	return 0;
}