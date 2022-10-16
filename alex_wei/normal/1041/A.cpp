#include<bits/stdc++.h>
using namespace std;
int n,mi=1e9,mx,a; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a,mi=min(mi,a),mx=max(mx,a);
	cout<<mx-mi+1-n;
	return 0;
}