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
#include <assert.h>
#include <bitset>
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
int T;
int a[100005];
int s,n;

void solve()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	int maxai=-1,maxk=-1,k=n;
	for(int i=0;i<n;i++)
	{
		s-=a[i];
		if(a[i]>maxai)
		{
			maxai=a[i];
			maxk=i;
		}
		if(s<0)
		{
			k=i;
			break;
		}
	}
	if(k==n)
	{
		puts("0");
		return;
	}
	if(a[k]>maxai) puts("0");else printf("%d\n",maxk+1);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}