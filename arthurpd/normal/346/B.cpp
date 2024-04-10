#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define inf (0x3f3f3f3f)

char s1[112], s2[112], s3[112];
int m;
int foo[112];
bool been[112][112][112];
int tab[112][112][112];

int pd(int i, int j, int k)
{
	if(k == m)
		return -inf;
	if(s1[i] == '\0' || s2[j] == '\0')
		return 0;
	if(been[i][j][k])
		return tab[i][j][k];

	int retv = -inf;
	retv = max(retv, pd(i, j+1, k));
	retv = max(retv, pd(i+1, j, k));

	if(s1[i] == s2[j])
	{
		int next = k;
		while(1)
		{
			if(s3[next] == s1[i])
			{
				retv = max(retv, pd(i+1, j+1, next+1) + 1);
				break;
			}
			if(next == 0)
			{
				retv = max(retv, pd(i+1, j+1, 0) + 1);
				break;
			}
			next = foo[next];
		}
	}
	been[i][j][k] = true;
	return tab[i][j][k] = retv;
}

int find(int i, int k)
{
	if(s3[k] == s3[foo[i]])
		return foo[i] + 1;
	if(foo[i] == 0)
		return 0;
	return find(foo[i], k);
}

int main(void)
{
	scanf("%s %s %s", s1, s2, s3);
	m = strlen(s3);
	foo[0] = foo[1] = 0;
	for(int i = 2; i <= m; i++)
		foo[i] = find(i - 1, i - 1);

	if(pd(0,0,0) == 0)
	{
		printf("0\n");
		return 0;
	}
	for(int i = 0, j = 0, k = 0; s1[i] != '\0' && s2[j] != '\0';)
	{
		if(tab[i][j][k] == tab[i][j+1][k])
			j++;
		else if(tab[i][j][k] == tab[i+1][j][k])
			i++;
		else
		{
			printf("%c", s1[i]);
			int next = k;
			while(1)
			{
				if(tab[i][j][k] == tab[i+1][j+1][next+1] + 1)
				{
					i++, j++, k = next+1;
					break;
				}
				if(next == 0)
				{
					i++, j++, k = 0;
					break;
				}
				next = foo[next];
			}
		}
	}
	printf("\n");
}