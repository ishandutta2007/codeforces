#include<cstdio>
#include<algorithm>
using namespace std;

char s[1111];
int t[1111], l[1111], r[1111], ti[1111];

int main()
{
	int n;
	scanf("%d %s", &n, &s[1]);
	for(int i = 0; i < n; i++)
	{
		l[i] = r[i] = n;
		if(i != 0)
		{
			int j = i;
			while(j >= 0 && s[j] == '=') j--;
			if(j < 0 || s[j] == 'R') l[i] = j-1;
			else l[i] = -1;
		}
		if(i != n-1)
		{
			int j = i+1;
			while(j < n && s[j] == '=') j++;
			if(j == n || s[j] == 'L') r[i] = j;
			else r[i] = -1;
		}
		//printf(" %d %d\n", l[i], r[i]);
	}
	t[n] = ti[n] = 1;
	for(int c = 1; c <= n; c++)
	{
		for(int i = 0; i < n; i++) if(t[i] == 0)
		{
			if(l[i] != -1 && ti[l[i]] == 0) continue;
			if(r[i] != -1 && ti[r[i]] == 0) continue;
			t[i] = c;
		}
		for(int i = 0; i < n; i++) ti[i] = t[i];
	}
	for(int i = 0; i < n; i++)
		printf("%d ", t[i]);
	printf("\n");
}