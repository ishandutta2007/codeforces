#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a,b,ans;
string s;
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>a>>b>>s;
		ll posl=0,posr=n-1,ans=0,cnt=0;
		while(posl<n&&s[posl]=='0')posl++;
		if(posl==n){cout<<n*a+(n+1)*b<<endl;continue;}
		while(posr>=0&&s[posr]=='0')posr--;
		ans=b*(n+1)+a*(n+2);
		for(int i=1;i<n;i++)
			if(s[i]=='1'&&s[i-1]=='0')
				ans+=b;
		for(int i=posl;i<=posr;i++){
			if(s[i]=='0')cnt++;
			else{
				ans+=min(2*a,max((ll)0,cnt-1)*b);
				cnt=0;
				ans+=b;
			}
//			cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
    return 0;
}