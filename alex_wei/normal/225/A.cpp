#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,x,a,b,w,pd[7]; 
int main()
{
	cin>>n>>x>>a>>b;
	for(int i=1;i<n;i++){
		memset(pd,0,sizeof(pd));
		x=7-x;
		cin>>a>>b;
		pd[a]=pd[7-a]=pd[b]=pd[7-b]=1;
		if(pd[x])cout<<"NO",exit(0);
		x=7-x;
	}
	cout<<"YES";
    return 0;
}