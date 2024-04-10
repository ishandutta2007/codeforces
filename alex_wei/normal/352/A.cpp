#include<bits/stdc++.h>
using namespace std;
int m,s,f; 
int main()
{
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>s,f+=(s==5);
	if(f==m)cout<<-1,exit(0);
	else if(f<9)cout<<0,exit(0);
	else{
		for(int i=1;i<=f/9;i++)
			cout<<"555555555";
		for(int i=m;i>f;i--)cout<<"0";
	}
    return 0;
}