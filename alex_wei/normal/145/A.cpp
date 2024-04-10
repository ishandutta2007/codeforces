#include<bits/stdc++.h>
using namespace std;
string a,b;
int x,y; 
int main()
{
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
		if(a[i]!=b[i])
			a[i]=='7'?x++:y++;
	cout<<x+y-min(x,y);
	return 0;
}