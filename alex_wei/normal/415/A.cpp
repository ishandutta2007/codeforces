#include<bits/stdc++.h>
using namespace std;
int n,m,b[150],a;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a;
		for(int j=a;j<=n;j++)
			if(!b[j])
				b[j]=a;
	}
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	return 0;
}