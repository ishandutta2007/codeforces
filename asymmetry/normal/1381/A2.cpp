#include <bits/stdc++.h>

using namespace std;

int gh, l, n;
char c1[100001];
char c2[100001];
int s1[100001];
int s2[100001];
vector <int> odp;

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d", &n);
		scanf("%s", c1+1);
		scanf("%s", c2+1);
		for(int i=1; i<=n; ++i)
		{
			s1[i]=c1[i]-'0';
			s2[i]=c2[i]-'0';
		}
		odp.clear();
		l=0;
		for(int i=1; i<=n; ++i)
		{
			if(i&1) // rosnaco
			{
				if((s1[(i>>1)+1]^l)==s2[n-i+1]) // robimy flip
				{
					s1[(i>>1)+1]^=1;
					odp.push_back(1);
				}
				odp.push_back(n-i+1);
			}
			else // malejaco
			{
				if((s1[n-(i>>1)+1]^l)==s2[n-i+1]) // robimy flip
				{
					s1[n-(i>>1)+1]^=1;
					odp.push_back(1);
				}
				odp.push_back(n-i+1);
			}
			l^=1;
		}
		printf("%d ", (int)odp.size());
		for(int i:odp)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}