#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <queue>
#include <utility>
using namespace std;
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second

ll num1[100],num2[100];

int main()
{
	ll n,m,i,j,k,ans=1e18,tmp;
	cin >> n >> m;
	for(i=0;i<n;i++)
		cin >> num1[i];
	for(i=0;i<m;i++)
		cin >> num2[i];
	for(i=0;i<n;i++)
	{
		tmp=-1e18;
		for(j=0;j<n;j++)
		{
			if(i==j) continue;
			for(k=0;k<m;k++)
				tmp=max(num1[j]*num2[k],tmp);
		}
		ans=min(tmp,ans);
	}
	cout << ans << "\n";
}