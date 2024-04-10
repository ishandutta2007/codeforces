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
	ll mi=0,mix=1,mixn=0,n,k,i,tmp;
	cin >> n >> k;
	for(i=1;i<=k;i++)
	{
		cin >> tmp;
		if(n/tmp*tmp>mi) mi=n/tmp*tmp,mix=i,mixn=n/tmp;
	}
	cout << mix << " " << mixn << "\n";
}