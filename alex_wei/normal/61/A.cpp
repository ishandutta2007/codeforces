#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
	cin>>a>>b;
	for(int i=0;i<a.size();i++)cout<<(a[i]!=b[i]);
	return 0;
}