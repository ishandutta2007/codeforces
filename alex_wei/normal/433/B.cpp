#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,v[100005],s[2][100005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>v[i],s[0][i]=s[0][i-1]+v[i];
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++)
		s[1][i]=s[1][i-1]+v[i];
	cin>>m;
	for(int i=0;i<m;i++){
		int k,l,r;
		cin>>k>>l>>r;
		cout<<s[k-1][r]-s[k-1][l-1]<<endl;
	}
	return 0;
}