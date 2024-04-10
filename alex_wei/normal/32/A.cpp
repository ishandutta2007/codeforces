#include<bits/stdc++.h>
using namespace std;
int n,d,a[1002],s;
int main()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(abs(a[i]-a[j])<=d)s++;
	cout<<s-n;
    return 0;
}