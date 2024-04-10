#include<bits/stdc++.h>
using namespace std;
double n,m,k,x,r1,p1,p2=1e9,A,B;
int main()
{
	cin>>n;for(int i=1;i<=n;i++)cin>>x,r1=max(r1,x);
	cin>>m;for(int i=1;i<=m;i++)cin>>x,p1=max(p1,x);
	cin>>k;for(int i=1;i<=k;i++)cin>>x,p2=min(p2,x);
	cin>>A>>B;printf("%.9lf",sqrt(r1*r1/(A*p2/B/p1+1)));
}