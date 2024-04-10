#include <bits/stdc++.h>

using namespace std;

int gh, n, a, b;
int t[30][30];
char s1[100001];
char s2[100001];

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		for(int i=0; i<20; ++i)
		{
			for(int j=0; j<20; ++j)
			{
				t[i][j]=0;
			}
		}
		scanf("%d", &n);
		scanf("%s", s1);
		scanf("%s", s2);
		a=0;
		for(int i=0; i<n; ++i)
		{
			++t[s1[i]-'a'][s2[i]-'a'];
			if(s1[i]>s2[i])
			{
				a=1;
				break;
			}
		}
		if(a)
		{
			printf("-1\n");
			continue;
		}
		a=0;
		for(int i=0; i<20; ++i)
		{
			for(int j=i+1; j<20; ++j)
			{
				if(t[i][j])
				{
					++a;
					b=j;
					while(j<20)
					{
						t[b][j]+=t[i][j];
						++j;
					}
				}
			}
		}
		printf("%d\n", a);
	}
	return 0;
}