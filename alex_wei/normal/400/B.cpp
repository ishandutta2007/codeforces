#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],s,g,ans;
char x; 
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>x;
			if(x=='S')s=j;
			if(x=='G')g=j;
		}
		if(g>s)cout<<-1,exit(0);
		ans+=!a[s-g];
		a[s-g]=1;
	}
	cout<<ans;
	return 0; 
}