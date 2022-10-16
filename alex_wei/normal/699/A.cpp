#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans=1e9,pd;
string s;
int main()
{
	cin>>n>>s>>a;
	for(int i=1;i<n;i++){
		cin>>b;
		if(s[i-1]=='R'&&s[i]=='L')
			ans=min(ans,(b-a)/2),pd=1;
		a=b;
	}
	if(pd)cout<<ans;
	else cout<<-1;
    return 0;
}