#include<bits/stdc++.h>
using namespace std;
int n,a;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a,cout<<(a%2?a:a-1)<<" ";
	return 0;
}