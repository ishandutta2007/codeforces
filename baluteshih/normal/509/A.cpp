#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;

ll a[20][20];

int main()
{
	ll n,i,j;
	cin >> n;
	for(i=1;i<=n;i++)
		a[i][1]=a[1][i]=1;
	for(i=2;i<=n;i++)
		for(j=2;j<=n;j++)
			a[i][j]=a[i-1][j]+a[i][j-1];
	cout << a[n][n] << "\n";
}