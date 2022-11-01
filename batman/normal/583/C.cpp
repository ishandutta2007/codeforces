#include <bits/stdc++.h>
using namespace std;
int n,a[333333],b[555],t;
map <int,int> m;
int main()
{
	cin>>n;
	for(int i=0;i<n*n;i++)cin>>a[i],m[a[i]]++;
	sort(a,a+n*n);
	for(int i=n*n-1;i>=0;i--)
		if(m[a[i]]>0)
		{
			cout<<a[i]<<" ";
			for(int j=0;j<t;j++)m[__gcd(a[i],b[j])]-=2;
			b[t++]=a[i],m[a[i]]--;
		}	
    return 0;
}