#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

#define mod 1000000007
#define maxn 2222

int qpow(int a, int n)
{
	if(n == 0) return 1;
	int b = qpow(a,n/2);
	b= 1LL* b*b%mod;
	if(n&1) b=1LL*b*a%mod;
	return b;
}

int p[maxn], ct[maxn];
int n,m,k,q;

int fi(int a)
{
	return p[a] == a ? a : p[a]=  fi(p[a]);
}
void un(int a, int b)
{
	a = fi(a);
	b=  fi(b);
	if(a != b) p[a] = b;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++) p[i] = i;
	for(int i = 0; i+k <= n; i++)
	{
		for(int j = 0; 2*j < k; j++)
			un(i+j, i+k-j-1);
	}
	for(int i = 0; i < n; i++) ct[fi(i)]++;
	for(int i = 0; i < n; i++) if(ct[i] > 0) q++;
	printf("%d\n", qpow(m, q));
	return 0;
}