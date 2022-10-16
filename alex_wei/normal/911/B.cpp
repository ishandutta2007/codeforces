#include<bits/stdc++.h>
using namespace std;
int n,a,b; 
int main()
{
	cin>>n>>a>>b;
	for(int i=min(a,b);i>0;i--){
		int j=a/i+b/i;
		if(j>=n)
			cout<<i,exit(0);
	}
	return 0;
}