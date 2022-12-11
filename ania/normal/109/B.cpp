#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define err(...) fprintf(stderr, __VA_ARGS__)

typedef pair<int,int> pi;
typedef long long int64;
typedef vector<int> vi;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define x first
#define y second
#define mp make_pair
#define pb push_back

#define mm 1234

int pl,pr,vl,vr,k,q;
int all[mm];
int pp[mm], pv[mm], qp[mm], qv[mm];

int cut(int ax, int ay, int bx, int by)
{
	if(ay <= bx) return 0;
	if(by <= ax) return 0;
	return min(by,ay) - max(ax,bx);
}

int main()
{
	q = 1;
	for(int l = 1; l <= 9; l++)
	{
		for(int a = 0; a < (1<<l); a++)
		{
			int r = 0;
			fore(i,l) if(a&(1<<i)) r = r*10 + 7;
			else r = r*10 + 4;
			all[q++] = r;
		}
	}
	all[q++] = 1000000007;
	sort(all, all+q);
	long long res = 0;
	scanf("%d%d%d%d%d", &pl, &pr, &vl, &vr, &k);
	fore(kp,q)
	{
		if(kp == 0) continue;
		pp[kp] = cut(pl,pr+1,all[kp-1]+1,all[kp]+1);
		qp[kp] = cut(pl,pr+1,all[kp-1],all[kp]);
		//printf("pp[%d] = %d %d\n", kp, pp[kp], qp[kp]);
	}
	fore(kv,q)
	{
		if(kv == 0) continue;
		pv[kv] = cut(vl,vr+1,all[kv-1]+1,all[kv]+1);
		qv[kv] = cut(vl,vr+1,all[kv-1],all[kv]);
	}
	fore(kp, q)
	{
		if(kp-k >= 0) res += 1LL * qp[kp] * pv[kp-k];
		if(kp+k < q) res += 1LL * pp[kp] * qv[kp+k];
	}
	if(k == 1) fore(i,q) if(all[i] >= pl && all[i] >= vl && all[i] <= pr && all[i] <= vr) res--;
	printf("%.11lf\n", 1.0 * res / (pr-pl+1) / (vr-vl+1));
}