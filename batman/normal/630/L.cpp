#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (40)

string s;
ll num,ex,p;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	num=(s[1]-'0')+(s[3]-'0')*10+(s[4]-'0')*100+(s[2]-'0')*1000+(s[0]-'0')*10000;
	ex=num;
	for(int i=0;i<4;i++)
	{
		num*=ex;
		num%=100000;
	}
	ex=num;
	while(ex)p++,ex/=10;
	for(int i=0;i<4-p;i++)cout<<0;
	cout<<num;
	return 0;
}