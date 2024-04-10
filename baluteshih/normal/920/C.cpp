#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <queue>
#include <map> 
#include <math.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ll long long
#define iop(i,a,n) for(int i=a;i<n;i++)
using namespace std;

string vis;
int num[200000];

int main()
{
	int n,r;
	cin >> n;
	iop(i,0,n)
		cin >> num[i];
	cin >> vis;
	iop(i,0,n-1)
		if(vis[i]=='1')
		{
			for(r=i+1;r<n-1 && vis[r]=='1';r++) ;
			iop(j,i,r+1)
				if(num[j]<=i || num[j]>r+1)
					return cout << "NO\n",0;
			i=r;
		}
		else if(num[i]!=i+1)
			return cout << "NO\n",0;
	cout << "YES\n";
}