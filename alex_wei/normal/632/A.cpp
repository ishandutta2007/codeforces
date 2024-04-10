#include<bits/stdc++.h>
using namespace std;
long long n,p,sum,num;
string s[42];
int main()
{
	cin>>n>>p,p/=2;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=n;i>0;i--){
		if(s[i].size()>5)sum++;
		num+=sum,sum*=2;
	}
	cout<<num*p;
	return 0;
}