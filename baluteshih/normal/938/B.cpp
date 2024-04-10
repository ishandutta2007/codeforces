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

ll num[100005],ans[100005];

int main()
{
	ll n,i,sum=0;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> num[i];
	for(i=0;i<n;i++)
		ans[i]=num[i]-1;
	for(i=0;i<n;i++)
		ans[i]=min(ans[i],1000000-num[i]),sum=max(sum,ans[i]);
	cout << sum << "\n";
}