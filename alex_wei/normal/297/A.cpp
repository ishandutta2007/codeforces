#include<bits/stdc++.h>
using namespace std;
string a,b;
int x,y;
int main()
{
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
		x+=a[i]=='1';
	for(int i=0;i<b.size();i++)
		y+=b[i]=='1';
	if(x>=y||x%2&&x+1>=y)cout<<"YES";
	else cout<<"NO";
    return 0;
}