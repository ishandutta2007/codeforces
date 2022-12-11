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

#define M (1<<18)
#define MM (2*M+13)
#define maxn 150150

int n,q,c;

long long T[MM], MX[MM], MXL[MM], MXR[MM];
int x[maxn], p[maxn], F[maxn];

inline long long sum(int a, int b, int l, int r, int pos)
{
	if(a == l && b == r) return T[pos];
	int m = (l+r) / 2;
	if(a >= m) return sum(a,b,m,r,pos*2+1);
	if(b <= m) return sum(a,b,l,m,pos*2);
	return sum(a,m,l,m,pos*2) + sum(m,b,m,r,pos*2+1);
}

inline long long mxl(int a, int b, int l, int r, int pos)
{
	if(a == l && b == r) return MXL[pos];
	int m = (l+r) / 2;
	if(a >= m) return mxl(a,b,m,r,pos*2+1);
	if(b <= m) return mxl(a,b,l,m,pos*2);
	return max(mxl(a,m,l,m,pos*2), sum(a,m,l,m,pos*2) + mxl(m,b,m,r,pos*2+1));
}

inline long long mxr(int a, int b, int l, int r, int pos)
{
	if(a == l && b == r) return MXR[pos];
	int m = (l+r) / 2;
	if(a >= m) return mxr(a,b,m,r,pos*2+1);
	if(b <= m) return mxr(a,b,l,m,pos*2);
	return max(mxr(a,m,l,m,pos*2) + sum(m,b,m,r,pos*2+1), mxr(m,b,m,r,pos*2+1));
}

inline long long mx(int a, int b, int l, int r, int pos)
{
	//printf("mx %d %d %d %d %d\n", a,b,l,r,pos);
	if(a == l && b == r) return MX[pos];
	int m = (l+r) / 2;
	if(a >= m) return mx(a,b,m,r,pos*2+1);
	if(b <= m) return mx(a,b,l,m,pos*2);
	return max(mxr(a,m,l,m,pos*2) + mxl(m,b,m,r,pos*2+1), max(mx(a,m,l,m,pos*2), mx(m,b,m,r,pos*2+1)));
}


int main()
{
	long long res = 0;
	scanf("%d%d%d", &n, &q, &c);
	FOR(i,n) scanf("%d", &x[i]);
	FOR(i,n-1) scanf("%d", &p[i+1]);
	FORI(i,n-1) F[i] = (x[i] - x[i-1]) * 100 - 2 * c * p[i];
	FOR(i,n)
	{
		//printf("F[%d] = %d\n", i, F[i]);
		T[i+M] = F[i];
		if(F[i] > 0)
		{
			MXL[i+M] = MXR[i+M] = MX[i+M] = F[i];
		}
	}
	for(int i = M-1; i >= 1; i--)
	{
		T[i] = T[i*2] + T[i*2+1];
		MXL[i] = max(MXL[2*i], T[2*i] + MXL[2*i+1]);
		MXR[i] = max(MXR[2*i+1], T[2*i+1] + MXR[2*i]);
		MX[i] = max(MX[2*i], max(MX[2*i+1], MXR[2*i] + MXL[2*i+1]));
	}
	while(q--)
	{
		int a,b;
		scanf("%d%d", &a, &b);
		long long cur = mx(a,b,0,M,1);
		//printf("%lld\n", cur);
		res += cur;
	}
	printf("%.7lf\n", 1.0 * res / 200);
	return 0;
}