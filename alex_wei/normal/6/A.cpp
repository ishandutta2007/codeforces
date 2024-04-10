#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int k(int x,int y,int z)
{
	if(x+y>z&&y+z>x&&x+z>y)return 2;
	if(x+y==z||y+z==x||x+z==y)return 1;
	return 0;
}
int main()
{
	cin>>a>>b>>c>>d;
	if(k(a,b,c)==2||k(a,b,d)==2||k(a,c,d)==2||k(b,c,d)==2)cout<<"TRIANGLE";
	else if(k(a,b,c)||k(a,b,d)||k(a,c,d)||k(b,c,d))cout<<"SEGMENT";
	else cout<<"IMPOSSIBLE";
	return 0;
}