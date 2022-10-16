#include<bits/stdc++.h>
using namespace std;
int n,a,x,y;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a,x+=a;
	for(int i=1;i<=n;i++)cin>>a,y+=a;
	if(x>=y)cout<<"Yes";
	else cout<<"No";
    return 0;
}