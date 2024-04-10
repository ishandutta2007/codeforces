#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,d[125],s,t,a1,a2; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	cin>>s>>t;
	if(s>t)swap(s,t);
	for(int i=s;i<t;i++)
		a1+=d[i];
	for(int i=t;i!=s;i++){
		a2+=d[i];
		if(i+1>n)i=0;
	}
	cout<<min(a1,a2);
	return 0;
}