#include<bits/stdc++.h>
using namespace std;
int n,p[1002],d=1,w=1;
#define aba ababa
int main()
{
	cin>>n;
	if(n==1)cout<<"YES",exit(0);
	d=2,w=2;
	while(w!=1||d!=1)p[w]=1,w+=d,d++,d=(d-1)%n+1,w=(w-1)%n+1;
	for(int i=1;i<=n;i++)
		if(!p[i])cout<<"NO",exit(0);
	cout<<"YES"; 
	return 0;
}