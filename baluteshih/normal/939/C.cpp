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

ll num[200005],deq[200005];

int main()
{
	ll n,s,f,i,l=0,r=-1,ans=0,anss,sum=0,j;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> num[i];
	cin >> s >> f;
	for(i=f-1;i>s;i--)
		deq[++r]=i,sum+=num[i];
	for(i=1,j=s;i<=n;i++,j--)
	{
		deq[++r]=j,sum+=num[(j%n+n-1)%n+1];
		if(sum>ans) ans=sum,anss=i;
		sum-=num[(deq[l]%n+n-1)%n+1],l++;
	}
	cout << anss << "\n";
}