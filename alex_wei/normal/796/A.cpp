#include<bits/stdc++.h>
using namespace std;
int n,m,k,s[102];
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		if(m-i>0&&s[m-i]<=k&&s[m-i]||m+i<=n&&s[m+i]<=k&&s[m+i])cout<<i*10,exit(0);
    return 0;
}