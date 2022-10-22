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
int n,m;
int a[100005];
int b[100005];
bool use[100005];
int pos[100005];

void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
		pos[a[i]]=i;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",b+i);
		b[i]--;
	}
	int top=0;
	ll res=0;
	for(int i=0;i<m;i++)
	{
		if(pos[b[i]]<top) res++;
		else
		{
			res+=(pos[b[i]]-i)*2+1;
			top=pos[b[i]]+1;
		}
	}
	cout<<res<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}