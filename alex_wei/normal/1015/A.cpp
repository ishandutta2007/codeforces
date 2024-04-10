#include <bits/stdc++.h>
using namespace std;
int p[102],n,m; 
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;j++)
			p[j]=1;
	}
	for(int j=1;j<=m;j++)
		p[0]+=!p[j];
	cout<<p[0]<<endl;
	for(int j=1;j<=m;j++)
		if(!p[j])
			cout<<j<<" ";
    return 0;
}