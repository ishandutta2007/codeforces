#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a,b,c[100005],a1,a2;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a,c[a]=i;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b;
		a1+=c[b];
		a2+=n-c[b]+1;
	}
	cout<<a1<<" "<<a2;
	return 0;
}