#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,s;
int main()
{
	cin>>a>>b>>c>>d>>e;
	s=a+b+c+d+e;
	if(s%5||s==0)cout<<-1;
	else cout<<s/5; 
	return 0;
}