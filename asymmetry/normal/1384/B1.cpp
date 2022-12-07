#include <bits/stdc++.h>

using namespace std;

int gh, n, k, l, a, akt, gle1, gle2, gle11, gle22;
int t[300002];

#define D if(0)

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d%d%d", &n, &k, &l);
		a=1;
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", &t[i]);
		}
		t[0]=-1e9;
		t[n+1]=-1e9;
		akt=0;
		for(int i=0; i<=n; ++i)
		{
			D printf("(%d)\n", i);
			if(t[i]+k<=l)
			{
				gle1=k;
				gle2=k;
			}
			else
			{
				gle1=l-t[i];
				gle2=2*k-gle1;
			}
			D printf("akt=%d\n", akt);
			D printf("(%d %d)\n", gle1, gle2);
			if(akt>gle1 && akt<gle2)
			{
				a=0;
				break;
			}
			if(t[i+1]>l)
			{
				a=0;
				break;
			}
			if(t[i+1]+k<=l)
			{
				gle11=k;
				gle22=k;
			}
			else
			{
				gle11=l-t[i+1];
				gle22=2*k-gle11;
			}
			D printf("(%d %d)\n", gle11, gle22);
			if(gle1==k)
			{
				akt=gle22;
				continue;
			}
			if(akt<=gle1)
			{
				++akt;
				akt%=2*k;
			}
			else
			{
				if(gle22<=akt+1)
				{
					++akt;
					akt%=2*k;
				}
				else
				{
					akt=gle22;
				}
			}
		}
		if(a)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}