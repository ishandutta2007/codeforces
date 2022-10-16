#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
typedef long long ll;
using namespace std;
int a[101][52][2];
int main()
{
	IO;
	int n;
	string s;
	cin>>s;
	cin>>n;
	int l=s.length();
	for(int i=0; i<=100; i++)
		for(int j=0; j<=50; j++)
			for(int k=0; k<2; k++)
				a[i][j][k]=-1000;
	a[0][0][0]=0;
	for(int i=0; i<l; i++)
		for(int j=0; j<=i&&j<=n; j++)
			if(s[i]=='F')
			{
				a[i+1][j][0]=max(a[i+1][j][0],a[i][j][0]+1);
				a[i+1][j][1]=max(a[i+1][j][1],a[i][j][1]-1);
				a[i+1][j+1][1]=max(a[i+1][j+1][1],a[i][j][0]);
				a[i+1][j+1][0]=max(a[i+1][j+1][0],a[i][j][1]);
			}
			else
			{
				a[i+1][j+1][0]=max(a[i+1][j+1][0],a[i][j][0]+1);
				a[i+1][j+1][1]=max(a[i+1][j+1][1],a[i][j][1]-1);
				a[i+1][j][1]=max(a[i+1][j][1],a[i][j][0]);
				a[i+1][j][0]=max(a[i+1][j][0],a[i][j][1]);
			}
	int ans=0;
	for(int i=n; i>=0; i-=2)
	for(int j=0; j<2; j++)
		ans=max(ans,a[l][i][j]);
	for(int i=0; i<=100; i++)
		for(int j=0; j<=50; j++)
			for(int k=0; k<2; k++)
				a[i][j][k]=1000;
	a[0][0][0]=0;
	for(int i=0; i<l; i++)
		for(int j=0; j<=i&&j<=n; j++)
			if(s[i]=='F')
			{
				a[i+1][j][0]=min(a[i+1][j][0],a[i][j][0]+1);
				a[i+1][j][1]=min(a[i+1][j][1],a[i][j][1]-1);
				a[i+1][j+1][1]=min(a[i+1][j+1][1],a[i][j][0]);
				a[i+1][j+1][0]=min(a[i+1][j+1][0],a[i][j][1]);
			}
			else
			{
				a[i+1][j+1][0]=min(a[i+1][j+1][0],a[i][j][0]+1);
				a[i+1][j+1][1]=min(a[i+1][j+1][1],a[i][j][1]-1);
				a[i+1][j][1]=min(a[i+1][j][1],a[i][j][0]);
				a[i+1][j][0]=min(a[i+1][j][0],a[i][j][1]);
			}
	for(int i=n; i>=0; i-=2)
	for(int j=0; j<2; j++)
		ans=max(ans,-a[l][n][j]);
	cout<<ans<<endl;
}