#include<bits/stdc++.h>
using namespace std;

int x,y,xx,yy,ans;

int main() {
	cin>>x>>y>>xx>>yy;
	ans=max(2,abs(x-xx)+1)+max(2,abs(y-yy)+1);
	cout<<ans*2;
}