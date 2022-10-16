#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,t,a[1005],b[1005];
int main()
{
	cin>>n>>m>>k>>t;
	for(int i=1;i<=k;i++)
		cin>>a[i]>>b[i];
	while(t--){
		int x,y;
		cin>>x>>y;
		int d=(x-1)*m+y,pd=0;
		for(int i=1;i<=k;i++){
			if(a[i]==x&&b[i]==y)pd=1;
			if(a[i]<x||a[i]==x&&b[i]<y)
				d--;
		}
		if(pd)puts("Waste");
		else if(d%3==1)puts("Carrots");
		else if(d%3==2)puts("Kiwis");
		else puts("Grapes");
	}
    return 0;
}