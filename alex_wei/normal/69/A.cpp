#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,x,y,z;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a>>b>>c,x+=a,y+=b,z+=c;
	if(x==0&&y==0&&z==0)cout<<"YES";
	else cout<<"NO"; 
    return 0;
}