#include<bits/stdc++.h>
using namespace std;
int p[200009],q[200009];
int main(){
	ios::sync_with_stdio(0);
	int n,k,i,t=0;
	long long s=0;
	cin>>n>>k;
	for(i=1;i<=n;++i)cin>>p[i];
	for(i=1;i<=k;++i)s+=n-i+1;
	cout<<s<<' ';
	for(i=1;i<=n;++i)if(p[i]>n-k)q[++t]=i;
	s=1;
	for(i=1;i<t;++i)s=(s*(q[i+1]-q[i]))%998244353;
	cout<<s;
	return 0;
}//