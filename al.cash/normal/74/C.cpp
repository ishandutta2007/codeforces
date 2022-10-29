#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i=(a), _b=(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define INF 1000000000
#define INF_LL 1000000000000000000LL
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int h = 1111111;

int n,m, ans=0;
bool yu[h],yd[h];

int main()
{
	scanf("%d%d", &n, &m);
	if(n<m) swap(n, m);
	REP(i, n) if(!yu[i] && !yd[i])
	{
		++ans;
		int j = i, d = (i<n-1) ? 1 : -1;
		while(1)
		{
			//printf("%d,%d ", j, d);
			if(j<0 || j>=n) break;
			if(d==1)
			{
				if(yd[j]) break;
				yd[j] = 1;
			}
			else
			{
				if(yu[j]) break;
				yu[j] = 1;
			}
			int r = 2*(m-1);
			while(r>0)
			{
				if(d==1)
				{
					if(j+r<n-1) j+=r, r=0;
					else r-=(n-j-1), j=n-1, d=-1;
				}
				else
				{
					if(j-r>0) j-=r, r=0;
					else r-=j, j=0, d=1;
				}
			}
		}
		//printf("\n");
	}
	printf("%d\n", ans);
	//system("PAUSE");
	return 0;
}