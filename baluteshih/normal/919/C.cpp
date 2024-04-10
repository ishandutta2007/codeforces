#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ll long long
#define iop(i,a,n) for(int i=a;i<n;i++)
using namespace std;

string ma[2001];
int re[2001][2001];

int main()
{
	int n,m,k,ans=0;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
		cin >> ma[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ma[i][j-1]=='.')
			{
				re[i][j]=1+re[i-1][j];
				if(re[i][j]>=k) ans++;
			}
			else re[i][j]=0;
	if(k==1)
	{
		cout << ans << "\n";
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ma[i][j-1]=='.')
			{
				re[i][j]=1+re[i][j-1];
				if(re[i][j]>=k) ans++;
			}
			else re[i][j]=0;
	cout << ans << "\n";
}