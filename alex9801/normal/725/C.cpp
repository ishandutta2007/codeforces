#include <stdio.h>
#include <string.h>
#include <algorithm>

char arr[100];
char tmp[100];
char res[2][100];
bool chk[300];
int mem[300];

int main()
{
	int n = 27, h = 13, t, p, q, x, i;
	scanf("%s", arr);

	for(i = 0; i<n; i++)
	{
		if(chk[arr[i]])
		{
			p = mem[arr[i]];
			q = i;
			break;
		}
		chk[arr[i]] = 1;
		mem[arr[i]] = i;
	}

	if(p+1==q)
	{
		printf("Impossible");
		return 0;
	}

	t = (q-p-1)/2;

	x = 0;
	tmp[x++] = arr[p];
	for(i = p+1; i<q; i++)
		tmp[x++] = arr[i];
	for(i = q+1; i<n; i++)
		tmp[x++] = arr[i];
	for(i = 0; i<p; i++)
		tmp[x++] = arr[i];

	x = 0;
	for(i = t; i>=0; i--)
		res[0][i] = tmp[x++];
	for(i = 0; i<h; i++)
		res[1][i] = tmp[x++];
	for(i = h-1; i>t; i--)
		res[0][i] = tmp[x++];

	printf("%s\n%s", res[0], res[1]);
	return 0;
}