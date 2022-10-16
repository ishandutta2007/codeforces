#include <bits/stdc++.h>
using namespace std;
int n,t,p=1,c[30002];
int main()
{
	cin>>n>>t;
	for(int i=1;i<n;i++)
		cin>>c[i];
	while(p<t)p+=c[p];
	p==t?cout<<"YES":cout<<"NO";
    return 0;
}