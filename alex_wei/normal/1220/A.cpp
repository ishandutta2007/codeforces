#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,z,e,r,o,nn;
string s; 
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='z')z++;
		if(s[i]=='e')e++;
		if(s[i]=='r')r++;
		if(s[i]=='o')o++;
		if(s[i]=='n')nn++;
	}
	for(int i=1;i<=nn;i++)
		cout<<"1 ";
	for(int i=1;i<=z;i++)
		cout<<"0 ";
    return 0;
}