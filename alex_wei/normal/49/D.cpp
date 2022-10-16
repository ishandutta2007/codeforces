#include<bits/stdc++.h>
using namespace std;
int n,a,b;
string s; 
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
		if(i%2)s[i]=='1'?a++:b++;
		else s[i]=='1'?b++:a++;
	cout<<min(a,b);
	return 0;
}