#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main()
{
	cin>>n>>a>>b;
	cout<<min(n-a,b+1);
	return 0;
}