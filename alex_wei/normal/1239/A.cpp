#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int n,m,p[100005],x,y;
int main()
{
	cin>>n>>m;
	p[1]=2,p[2]=4;
	for(int i=3;i<=max(n,m);i++)
		p[i]=(p[i-1]+p[i-2])%mod;
	cout<<(p[n]+p[m]-2)%mod;
    return 0;
}