#include<bits/stdc++.h>
using namespace std;
int n,pos,l,r;
int main()
{
	cin>>n>>pos>>l>>r;
	if(l==1&&r==n)cout<<0;
	else if(l==1)cout<<abs(r-pos)+1;
	else if(r==n)cout<<abs(pos-l)+1;
	else if(pos-l>r-pos)cout<<abs(r-pos)+r-l+2;
	else cout<<abs(pos-l)+r-l+2;
	return 0;
}