#include<bits/stdc++.h>
using namespace std;
int pd=1,c[102],cnt,n;
string s; 
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='B'){
			cnt+=pd;
			c[cnt]++;
			pd=0;
		}
		else pd=1;
	}
	if(!cnt)cout<<0,exit(0);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<c[i]<<" ";
	return 0;
}