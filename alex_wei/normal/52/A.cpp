#include<bits/stdc++.h>
using namespace std;
int n,a[4],c;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&c),a[c]++;
	cout<<n-max(max(a[1],a[2]),a[3]);
	return 0;
}