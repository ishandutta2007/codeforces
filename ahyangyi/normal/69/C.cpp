#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int k, n, m, q;
char data[50][110];
char data2[50][110];
int recipe[50][50];
int ct[100][50], ct2[100][50];

struct xx {
	int name, count;
} lib[100];

bool operator < (const xx& a, const xx& b)
{
	char *aa, *bb;

	if (a.name < n)
		aa = data[a.name];
	else
		aa = data2[a.name - n];
	if (b.name < n)
		bb = data[b.name];
	else
		bb = data2[b.name - n];

	return strcmp(aa, bb) < 0;
}

int main ()
{
	scanf ("%d%d%d%d", &k, &n, &m, &q);
	for (int i = 0; i < n; i ++)
		scanf ("%s", data[i]);

	memset(recipe, 0, sizeof(recipe));

	for (int i = 0; i < m; i ++)
	{
		char bname[110], c;
		int x;

		scanf ("%s", data2[i]);
		data2[i][strlen(data2[i]) - 1] = 0;

		do
		{
			scanf ("%s%d%c", bname, &x, &c);
			int j = 0;
			while (strcmp(data[j], bname))
				j ++;

			recipe[i][j] = x;

		} while (c == ',');
	}

	memset(ct, 0, sizeof(ct));
	memset(ct2, 0, sizeof(ct2));

	for (int i = 0; i < q; i ++)
	{
		int id;
		char bname[110];

		scanf ("%d%s", &id, bname);

		id --;

		int j = 0;
		while (strcmp(bname, data[j])) j ++;

		ct[id][j] ++;

		for (int k = 0; k < m; k ++)
		{
			bool flag = true;
			for (int l = 0; l < n; l ++)
				if (ct[id][l] < recipe[k][l])
					flag = false;
			if (flag)
			{
				for (int l = 0; l < n; l ++)
					ct[id][l] -= recipe[k][l];
				ct2[id][k] ++;
			}
		}
	}

	for (int i = 0; i < k; i ++)
	{
		int p = 0;

		for (int j = 0; j < n; j ++)
			if (ct[i][j])
			{
				lib[p].name = j;
				lib[p].count = ct[i][j];
				p ++;
			}
		for (int j = 0; j < m; j ++)
			if (ct2[i][j])
			{
				lib[p].name = j + n;
				lib[p].count = ct2[i][j];
				p ++;
			}

		sort(lib, lib + p);

		printf ("%d\n", p);

		for (int i = 0; i < p; i ++)
		{
			if (lib[i].name < n)
				printf ("%s %d\n", data[lib[i].name], lib[i].count);
			else
				printf ("%s %d\n", data2[lib[i].name - n], lib[i].count);
		}
	}

	return 0;
}