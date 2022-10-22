#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,m;
ll time[300005];
ll p[300005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",time+i);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%I64d",p+i);
	}
	ll gcd=0;
	for(int i=0;i<n-1;i++)
	{
		gcd=__gcd(gcd,time[i+1]-time[i]);
	}
	for(int i=0;i<m;i++)
	{
		if(gcd%p[i]==0)
		{
			cout<<"YES\n";
			cout<<time[0]<<' '<<i+1<<endl;
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}