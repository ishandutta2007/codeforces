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

int love[5005];
bitset<5005> vis;

int main()
{
	int n,i;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> love[i];
	for(i=1;i<=n;i++)
		if(love[love[love[i]]]==i) break;
	if(i<=n) cout << "YES\n";
	else cout << "NO\n";
}