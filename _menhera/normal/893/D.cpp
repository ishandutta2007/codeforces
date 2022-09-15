#include<bits/stdc++.h>
using namespace std;


int N; long long D;

int main()
{
	scanf("%d%lld", &N, &D);
	long long s = 0, e = 0; int ans = 0;
	for(int i=0; i<N; ++i)
	{
		int v; scanf("%d", &v); int x = abs(v);
		if(v > 0)
		{
			s = s + x; e = min(e + x, D);
			if(s > e){puts("-1"); return 0;}
		}
		else if(v < 0)
		{
			s = s - x; e = e - x;
		}
		else
		{
			s = max(0LL, s);
			if(s > e)
			{
				++ans;
				s = 0; e = D;
			}
		}
	}	
	printf("%d\n", ans);
}