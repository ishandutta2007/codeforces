#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[103],p1=1,p2=1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[p1]<a[i])p1=i;
		if(a[p2]>=a[i])p2=i;
	}
	cout<<p1-1+n-p2-(p1>p2);
	return 0;
}