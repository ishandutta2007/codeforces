#include<bits/stdc++.h>
using namespace std;
int n,a[1002],l,r,c;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	l=1,r=n;
	sort(a+1,a+n+1);
	while(l<r){
		if(c%2)l++;
		else r--;
		c++;
	}
	cout<<a[l];
	return 0;
}