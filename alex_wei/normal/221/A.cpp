#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[1005];
void f(int x)
{
	if(x==1)return;
	swap(a[x],a[x-1]);
	f(x-1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i]=i;
	f(n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}