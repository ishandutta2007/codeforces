#include<bits/stdc++.h>
using namespace std;
map <int,int> s;
int n,k;
int main()
{
	for(int i=0;i<4;i++)cin>>k,n+=s[k],s[k]=1;
	cout<<n;
	return 0;
}