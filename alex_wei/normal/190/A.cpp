#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	cin>>n>>m;
	if(n==0&&m>0)cout<<"Impossible";
	else if(n==0)cout<<"0 0";
	else cout<<n+max(0,m-n)<<" "<<n+max(0,m-1);
	return 0;
}