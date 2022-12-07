#include <bits/stdc++.h>

using namespace std;

int gh, a, n;
int w[200001];
int t[200001];

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d", &n);
		w[0]=0;
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", &t[i]);
			w[i]=0;
		}
		for(int i=1; i<=n; ++i)
		{
			t[i]+=i;
			a=n;
			while(a+t[i]<0)
			{
				a<<=1;
			}
			t[i]+=a;
			t[i]%=n;
			++w[t[i]];
		}
		a=1;
		for(int i=0; i<n; ++i)
		{
			if(w[i]>1)
			{
				printf("NO\n");
				a=0;
				break;
			}
		}
		if(a)
		{
			printf("YES\n");
		}
	}
	return 0;
}