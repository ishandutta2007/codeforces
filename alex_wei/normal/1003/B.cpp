#include<bits/stdc++.h>
using namespace std;
int a,b,x;
void i(){while(a--)cout<<0;}void j(){while(b--)cout<<1;}
int main()
{
	cin>>a>>b>>x;if(x==1)i(),j(),exit(0);
	if(a>b){for(int i=0;i<x;i++)cout<<i%2,i%2?b--:a--;if(x%2)i(),j();else j(),i();}
	else{for(int i=1;i<=x;i++)cout<<i%2,i%2?b--:a--;if(x%2)j(),i();else i(),j();}
	return 0;
}