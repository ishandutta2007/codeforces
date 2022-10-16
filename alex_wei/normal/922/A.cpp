#include<bits/stdc++.h>
using namespace std;
int x,y;
int main()
{
	cin>>x>>y;
	if(y==0||y-1>x||(x-y+1)%2||y==1&&x>0)cout<<"No";
	else cout<<"Yes";
    return 0;
}