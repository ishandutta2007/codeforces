#include <bits/stdc++.h>
using namespace std;
int n,s,p[100002],c[100002];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==i)s++;
		else p[c[i]]=i;
	}
	if(s==n)cout<<s,exit(0);
	for(int i=0;i<n;i++)
		if(p[p[i]]==i&&p[i]!=i)
			cout<<s+2,exit(0);
	cout<<s+1;
    return 0;
}