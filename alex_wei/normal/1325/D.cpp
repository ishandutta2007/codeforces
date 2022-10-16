#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll u,v;
int main(){
	for(int i=1;i<=34;i++)for(int j=1;j<=34;j++)
		if((i^j)==12&&i+j==34)cout<<i<<" "<<j<<endl;
	cin>>u>>v;
	if(u>v)puts("-1"),exit(0);
	if(u==v&&!u)puts("0"),exit(0);
	if(u==v)cout<<"1\n"<<u,exit(0);
	ll rem=v-u;
	if(rem&1)puts("-1"),exit(0);
	else rem>>=1;
	if(u&rem)cout<<"3\n"<<u<<" "<<rem<<" "<<rem;
	else cout<<"2\n"<<(u|rem)<<" "<<rem<<endl;
	return 0;
}