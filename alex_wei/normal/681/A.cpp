#include<bits/stdc++.h>
using namespace std;
int n,a,b;
string s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>a>>b;
		if(a>=2400&&b>a)cout<<"YES",exit(0);
	}
	cout<<"NO";
	return 0;
}