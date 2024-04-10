#include<bits/stdc++.h>
using namespace std;
int n,c=1;
string s;
int main()
{
	cin>>n;
	while(s.size()<n){
		int k[5],t=0,r=c;
		while(r)k[++t]=r%10,r/=10;
		for(int i=t;i>0;i--)s+=(char)k[i]+'0';
		c++;
	}
	cout<<s[n-1];
	return 0;
}