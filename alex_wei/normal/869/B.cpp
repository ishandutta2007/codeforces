#include <bits/stdc++.h>
using namespace std;
long long a,b,s=1; 
int main()
{
	cin>>a>>b;
	if(b-a>=5)cout<<0,exit(0);
	while(b>a)s=(s*b)%10,b--;
	cout<<s;
    return 0;
}