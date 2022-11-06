#include <bits/stdc++.h>
using namespace std;

int qcnt = 0;
int query(vector<int> &v)
{
	assert(qcnt < 10000 && !v.empty());
	qcnt++;

	printf("%d ", (int)v.size());
	for(int x : v)
		printf("%d ", x + 1);
	puts("");
	fflush(stdout);

	int r;
	scanf("%d", &r);
	assert(r != -1);
	return r - 1;
}

bool chk[1010];

int main()
{
	int n;
	scanf("%d", &n);
	if(n <= 3)
	{
		puts("0");
		return 0;
	}

	int bs = sqrt(n + 0.5);
	int bcnt = n / bs;

	vector<int> can;
	for(int i = 0; i < n; i++)
		if(i % bs != 0)
			can.push_back(i);

	int p = 0;
	int cnt = 0;
	while(1)
	{
		bool ok = 0;
		vector<int> v;
		for(int x : can)
		{
			if(!chk[x])
			{
				chk[x] = 1;
				v.push_back(x);
				if((int)v.size() == bs)
				{
					ok = 1;
					cnt += bs;
					int r = query(v);
					for(int i = r; i < r + bs; i++)
					{
						if(chk[i % n])
						{
							cnt--;
							chk[i % n] = 0;
						}
					}
					break;
				}
			}
		}
		if(!ok || cnt == p)
		{
			puts("0");
			return 0;
		}

		p = cnt;
	}
	return 0;
}