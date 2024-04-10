#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
	cin>>a>>b>>c>>d;
	cout<<(((a^b)&(c|d))^((b&c)|(a^d)));
	return 0;
}