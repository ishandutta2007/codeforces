#include<bits/stdc++.h>
using namespace std;
int x,y,z; 
int main()
{
	cin>>x>>y>>z;
	if(x-y-z>0)cout<<"+";
	else if(x-y+z<0)cout<<"-";
	else if(x-y+z>=0&&x-y-z<0||x-y+z>0&&x-y-z<=0)cout<<"?";
	else cout<<"0";
	return 0;
}