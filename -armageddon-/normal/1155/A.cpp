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
char c[300005];
int n;
pair<char,int> pre[300005];
pair<char,int> suf[300005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	scanf("%s",c);
	for(int i=1;i<n;i++)
	{
		if(c[i]<c[i-1])
		{
			cout<<"YES\n";
			cout<<i<<' '<<i+1<<endl;
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}