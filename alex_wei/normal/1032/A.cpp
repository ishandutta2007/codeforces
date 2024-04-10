#include<bits/stdc++.h>
using namespace std;
int n,k,c[102],s,p,t;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p,c[p]++,t=max(t,c[p]);
	for(int i=1;i<101;i++)
		if(c[i])s++;
	while(t%k)t++;
	cout<<(int)t*s-n;
    return 0;
}