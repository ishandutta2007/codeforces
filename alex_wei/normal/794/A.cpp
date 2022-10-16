#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,n,s;
int main()
{
	cin>>a>>b>>c>>d;
	for(int i=1;i<=d;i++)cin>>s,n+=(s>b&&s<c);
	cout<<n;
    return 0;
}