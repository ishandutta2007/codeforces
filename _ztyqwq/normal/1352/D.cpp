#include <bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int pre = 0, cnta = 0, cntb = 0;
		int cnt = 0;
		for(int l = 0, r = n + 1; l + 1 < r;)
		{
			int tota = 0, totb = 0;
			if(l + 1 < r)
				cnt++;
			while(l + 1 < r && tota <= pre)
				cnta += a[++l], tota += a[l];
			pre = tota;
			if(l + 1 < r)
				cnt++;
			while(l + 1 < r && totb <= pre)
				cntb += a[--r], totb += a[r];
			pre = totb;
		}
		printf("%d %d %d\n", cnt, cnta, cntb);
	}
	return 0;
}