#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[100005],s1,s2;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++)
		s1+=a[i];
	for(int i=n/2+1;i<=n;i++)
		s2+=a[i];
	cout<<s1*s1+s2*s2<<endl;
    return 0;
}