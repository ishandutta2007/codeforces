#include<bits/stdc++.h>
using namespace std;
int n,ans,h[102],s[102];
char k[102][102];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>k[i][j];
			if(k[i][j]=='C')h[i]++,s[j]++;
		}
	for(int i=1;i<=n;i++)ans+=h[i]*(h[i]-1)/2+s[i]*(s[i]-1)/2;
	cout<<ans;
	return 0;
}