#include<bits/stdc++.h>
using namespace std;
int a,b,s,t;
int main()
{
	cin>>a>>b>>s;
	t=abs(a)+abs(b);
	if(t>s||(s-t)%2)cout<<"No";
	else cout<<"Yes";
	return 0;
}