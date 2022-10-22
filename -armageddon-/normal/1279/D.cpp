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
const int mod=998244353;
using namespace std;
vector <int> vec[1000005];
int len[1000005];

namespace combinatorics
{
	int *fac;
	int *ifac;
	int __Tmod;
	inline int add(int a,int b)
	{
		return (a+b)%__Tmod;
	}
	inline int sub(int a,int b)
	{
		return (a-b+__Tmod)%__Tmod;
	}
	inline int mult(int a,int b)
	{
		return (1LL*a*b)%__Tmod;
	}
	inline int fastpow(int basic,int x)
	{
		int res=1;
		while(x)
		{
			if(x&1)	res=mult(res,basic);
			basic=mult(basic,basic);
			x>>=1;
		}
		return res;
	}
	inline int inv(int x)
	{
		return fastpow(x,__Tmod-2);
	}
	void init(int n,int tmod)
	{
		__Tmod=tmod;
		fac=new int[n+5];
		ifac=new int[n+5];
		fac[0]=1;
		for(int i=1;i<=n;i++)
		{
			fac[i]=mult(fac[i-1],i);
		}
		ifac[n]=inv(fac[n]);
		for(int i=n-1;i>=0;i--)
		{
			ifac[i]=mult(ifac[i+1],i+1);
		}
	}
	inline int C(int n,int m)
	{
		return mult(mult(fac[n],ifac[m]),ifac[n-m]);
	}
	inline int Cat(int x)
	{
		return mult(C(x*2,x),inv(x+1));
	}
};
using namespace combinatorics;

int main()
{
//	freopen("input.txt","r",stdin);
	init(0,998244353);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		len[i]=k;
		int x;
		for(int j=0;j<k;j++)
		{
			cin>>x;
//			x--;
			vec[x].push_back(i);
		}
	}
	int res=0;
	for(int type=1;type<=1000000;type++)
	{
		if(vec[type].size()==0) continue;
		int sum=0;
		for(int i=0;i<vec[type].size();i++)
		{
			sum=add(sum,inv(len[vec[type][i]]));
		}
//		sum=mult(sum,sum);
		sum=mult(sum,vec[type].size());
		res=add(res,sum);
	}
	res=mult(res,inv(n));
	res=mult(res,inv(n));
	cout<<res<<endl;
	return 0;
}