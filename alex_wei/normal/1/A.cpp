#include<bits/stdc++.h>
using namespace std;
long long a,n,m;
int main()
{
	cin>>n>>m>>a;
	cout<<((n-1)/a+1)*((m-1)/a+1);
	return 0;
}