#include<bits/stdc++.h>
using namespace std;
int n,p[128];
char s;
int main()
{
	cin>>n;
	if(n==1)cout<<"Yes",exit(0);
	for(int i=0;i<n;i++){
		cin>>s;
		if(p[s])cout<<"Yes",exit(0);
		p[s]++;
	}
	cout<<"No";
	return 0;
}