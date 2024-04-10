#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int a,b,d,x,y,ans;
int main()
{
	cin>>a>>b,d=gcd(a,b);
	x=a/d,y=b/d;
//	cout<<x<<" "<<y<<endl;
	while(x%2==0)x/=2,ans++;
	while(x%3==0)x/=3,ans++;
	while(x%5==0)x/=5,ans++;
	while(y%2==0)y/=2,ans++;
	while(y%3==0)y/=3,ans++;
	while(y%5==0)y/=5,ans++;
	if(x!=1||y!=1)cout<<-1;
	else cout<<ans;
	return 0;
}