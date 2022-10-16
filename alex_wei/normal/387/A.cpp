#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,c,d;
char s; 
int main()
{
	cin>>a>>s>>b>>c>>s>>d;
	b-=d;
	if(b<0)b+=60,a--;
	a-=c;
	if(a<0)a+=24;
	cout<<a/10<<a%10<<":"<<b/10<<b%10;
	return 0;
}