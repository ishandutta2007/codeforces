#include<bits/stdc++.h>
using namespace std;
string a[3];
bool cmp(string a,string b){return a[1]<b[1]||a[1]==b[1]&&a[0]<b[0];}
int main()
{
	cin>>a[0]>>a[1]>>a[2];
	if(a[0]==a[1]&&a[1]==a[2])
		cout<<0,exit(0);
	sort(a,a+3,cmp);
	if(a[0][1]==a[1][1]&&a[1][1]==a[2][1]&&a[0][0]+1==a[1][0]&&a[1][0]+1==a[2][0])
		cout<<0,exit(0);
	if(a[0][1]==a[1][1]&&a[0][0]+1==a[1][0])
		cout<<1,exit(0);
	if(a[1][1]==a[2][1]&&a[1][0]+1==a[2][0])
		cout<<1,exit(0);
	if(a[0][1]==a[1][1]&&a[0][0]+2==a[1][0])
		cout<<1,exit(0);
	if(a[1][1]==a[2][1]&&a[1][0]+2==a[2][0])
		cout<<1,exit(0);
	if(a[0]==a[1]||a[1]==a[2])
		cout<<1,exit(0);
	cout<<2;
    return 0;
}