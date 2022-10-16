#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,h,a,b,k,fa,fb,ta,tb;
int main()
{
	cin>>n>>h>>a>>b>>k;
	for(int i=0;i<k;i++){
		cin>>ta>>fa>>tb>>fb;
		if(ta==tb){cout<<abs(fa-fb)<<endl;continue;}
		ll ans=0;
		if(fa>b)ans+=fa-b,fa=b;
		else if(fa<a)ans+=a-fa,fa=a;
		ans+=abs(ta-tb)+abs(fa-fb);
		cout<<ans<<endl;
	}
	return 0;
}