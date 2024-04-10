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

int main()
{
	ll t,x,i,n,a,flag,m,l,r;
	cin >> t;
	while(t--)
	{
		cin >> x,flag=0;
		if(x==0)
		{
			cout << "1 1\n";
			continue;
		}
		for(i=1;i*i<x && !flag;i++)
		{
			if(x%i) continue;
			if((i+x/i)&1) continue;
			n=(i+x/i)/2;
			a=n-i;
			//cout << n << " " << a << "\n";
			for(l=1,r=n;l<r;)
			{
				m=(l+r)/2;
				//cout << m << " " << (n-m)/m+1 << "\n";
				if((n-m)/m+1>a) l=m+1;
				else r=m; 
			}
			if((n-l)/l+1==a) flag=1,m=l;
		}
		if(flag) cout << n << " " << m << "\n";
		else cout << "-1\n";
	}
}