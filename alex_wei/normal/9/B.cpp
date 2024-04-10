#include<bits/stdc++.h>
using namespace std;
double xx,yy,x[102],dis[102],t[102],n,vb,vs;
int num=2;
int main()
{
	cin>>n>>vb>>vs;
	for(int i=1;i<=n;i++)cin>>x[i];
	cin>>xx>>yy;
	for(int i=1;i<=n;i++)dis[i]=sqrt(yy*yy+(xx-x[i])*(xx-x[i])),t[i]=x[i]/vb+dis[i]/vs;
	for(int i=3;i<=n;i++)
		if(t[i]<t[num]||t[i]==t[num]&&dis[i]<dis[num])
			num=i;
	cout<<num;
    return 0;
}