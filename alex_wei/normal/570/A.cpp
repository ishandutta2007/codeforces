#include<bits/stdc++.h>
using namespace std;
int n,m,d[102],k[102]; 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int s=-1,t=0;
		for(int j=1;j<=n;j++){
			cin>>k[j];
			if(k[j]>s)s=k[j],t=j;
		}
		d[t]++;
	}
	int s=-1,t=0;
	for(int i=1;i<=n;i++)
		if(d[i]>s)s=d[i],t=i;
	cout<<t;
	return 0;
}