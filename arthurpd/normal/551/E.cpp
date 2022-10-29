//http://codeforces.com/contest/551/problem/E

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define x first
#define y second

typedef pair<long long,long long> pii;

long long a[512345];
long long sqn = 707, nb;

long long dx[1123];
long long bl[1123], br[1123];
vector<pair<long long, long long> > bucket[1123];

int
main(void)
{
	long long n, q, tp, l, r, x;
	scanf("%lld %lld", &n, &q);
	for(long long i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for(long long i = 0; i < n; i++)
		bucket[i / sqn].push_back(pii(a[i], i));
	nb = ((n-1) / sqn) + 1;
	for(long long i = 0; i < nb; i++)
		bl[i] = i*sqn, br[i] = min(i*sqn + sqn - 1, n-1);
	for(long long i = 0; i < nb; i++)
		sort(bucket[i].begin(), bucket[i].end());
	while(q--)
	{
		scanf("%lld", &tp);
		if(tp == 1)
		{
			scanf("%lld %lld %lld", &l, &r, &x);
			l--, r--;
			for(long long i = 0; i < nb; i++)
			{
				if(bl[i] >= l && br[i] <= r)
					dx[i] += x;
				else if(max(bl[i], l) <= min(br[i], r))
				{
					for(long long j = 0; j < bucket[i].size(); j++)
						if(bucket[i][j].y >= l && bucket[i][j].y <= r)
							bucket[i][j].x += x;
					sort(bucket[i].begin(), bucket[i].end());
				}
			}
		}
		else
		{
			scanf("%lld", &x);
			long long lmost = n, rmost = -1;
			for(long long i = 0; i < nb; i++)
			{
				//prlong longf("hey %d\n", nb);
				vector<pii>::iterator it = lower_bound(bucket[i].begin(), bucket[i].end(), pii(x - dx[i], -1));
				if(it != bucket[i].end() && it->x == x - dx[i])
					lmost = min(lmost, it->y);
				else
					continue;
				it = upper_bound(bucket[i].begin(), bucket[i].end(), pii(x - dx[i], 0x3f3f3f3f));
				it--;
					rmost = max(rmost, it->y);
				//prlong longf("%d %d\n", rmost, lmost);
			}
			if(rmost != -1)
				printf("%I64d\n", rmost - lmost);
			else	
				printf("-1\n");
		}
	}
}