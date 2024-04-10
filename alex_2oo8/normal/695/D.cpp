#include <bits/stdc++.h>
#define MAXN 1005
#define MAXS 100005

using namespace std;

int main() {
	int days[2][13] = {{-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

	int S, M, H, DAY, DATE, MONTH;
	scanf("%d %d %d %d %d %d",&S,&M,&H,&DAY,&DATE,&MONTH);

	static pair<long long, int> a[MAXN];
	static long long res[MAXN];
	int N;
	scanf("%d",&N);
	int i;
	long long t;
	for (i = 0; i < N; i++)
	{
		scanf("%lld",&t);
		a[i] = make_pair(t, i);
		res[i] = -1;
	}
	sort(a, a+N);

	int s, m, h;
	static char b[MAXS];
	memset(b,0,sizeof(b));
	static int next[MAXS];
	for (h = 0; h < 24; h++)
	{
		for (m = 0; m < 60; m++)
		{
			for (s = 0; s < 60; s++)
			{
				if (((H == -1) || (H == h)) && ((M == -1) || (M == m)) && ((S == -1) || (S == s)))
				{
					b[h * 60 * 60 + m * 60 + s] = 1;
				}
			}
		}
	}
	next[86400] = -1;
	int ss;
	for (ss = 86399; ss >= 0; ss--)
	{
		next[ss] = next[ss+1];
		if (b[ss]) next[ss] = ss;
	}

	int pos = 0;
	t = 0LL;
	int day, date, month, year;
	day = 4;
	date = 1;
	month = 1;
	year = 1970;

	long long tDay = 24LL * 60LL * 60LL;

	while (pos < N)
	{
		//printf("%02d/%02d/%d\n",date,month,year);

		char isRun = 0;
		if ((MONTH == -1) || (MONTH == month))
		{
			if ((DAY != -1) && (DATE != -1))
			{
				if ((DAY == day) || (DATE == date)) isRun = 1;
			}
			else
			{
				if (((DAY == -1) || (DAY == day)) && ((DATE == -1) || (DATE == date))) isRun = 1;
			}
		}

		if (isRun)
		{
			while (pos < N)
			{
				if (a[pos].first < t)
				{
					res[a[pos].second] = t + (long long)(next[0]);
					pos++;
				}
				else if (a[pos].first < (t + tDay))
				{
					int nx = next[(int)(a[pos].first - t) + 1];
					if (nx != -1)
					{
						res[a[pos].second] = t + (long long)(nx);
						pos++;
					}
					else break;
				}
				else break;
			}
		}

		t += tDay;
		day++;
		if (day > 7) day = 1;
		date++;
		int isLeap = 0;
		if (((year % 400) == 0) || (((year % 100) != 0) && ((year % 4) == 0))) isLeap = 1;
		if (date > days[isLeap][month])
		{
			date = 1;
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}

	}

	for (i = 0; i < N; i++)
	{
		printf("%lld\n",res[i]);
	}

	return 0;
}