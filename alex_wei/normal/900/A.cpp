#include<bits/stdc++.h>
using namespace std;
int n,x,y,a,b; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x>>y,x>0?a++:b++;
	if(a<2||b<2)cout<<"Yes";
	else cout<<"No"; 
	return 0;
}