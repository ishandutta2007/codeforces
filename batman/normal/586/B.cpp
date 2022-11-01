#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (111)
ll n,a,b[N],l[N],r[N],p[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++)cin>>a,l[i]=l[i-1]+a;
	for(int i=1;i<n;i++)cin>>b[i];
	for(int i=n-1;i>0;i--)r[i]=r[i+1]+b[i];
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		p[i]+=l[i]+r[i+1];
	}
	sort(p,p+n);
	cout<<p[0]+p[1];
    return 0;
}