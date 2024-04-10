#include<bits/stdc++.h>
using namespace std;
int n,c,a,t;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a,t=max(t,a),c+=i>=t;
	cout<<c;
	return 0;
}