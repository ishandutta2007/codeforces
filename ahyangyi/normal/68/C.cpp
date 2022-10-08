#include <stdio.h>

int n;
int in[6], out[6];
int l[6][6], u[6][6], c[6][6];

int bf, bc;

void dfs (int s, int t, int cf, int cc)
{
//	printf ("%d %d %d %d\n", s, t, cf, cc);
	if (t == s + 1 && s - 1 > 0 && in[s - 1] != out[s - 1])
		return;

	if (s == n - 1)
	{
		if (bf == -1 || cf < bf || cf == bf && cc > bc)
		{
			bf = cf;
			bc = cc;
		}

		return;
	}

	for (int i = l[s][t]; i <= u[s][t]; i ++)
	{
		int new_cf, new_cc;
		
		new_cf = cf;
		new_cc = cc;

		in[t] += i;
		out[s] += i;

		if (s == 0)
			new_cf += i;
		if (i)
			new_cc += c[s][t] + i * i;

		if (t == n - 1)
			dfs (s + 1, s + 2, new_cf, new_cc);
		else
			dfs (s, t + 1, new_cf, new_cc);

		in[t] -= i;
		out[s] -= i;
	}
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n * (n - 1) / 2; i ++)
	{
		int a, b, _l, _u, _c;

		scanf ("%d%d%d%d%d", &a, &b, &_l, &_u, &_c);

		a --; b --;

		l[a][b] = _l;
		u[a][b] = _u;
		c[a][b] = _c;
	}

	for (int i = 0; i < n; i ++)
		in[i] = out[i] = 0;

	bf = bc = -1;

	dfs (0, 1, 0, 0);

	printf ("%d %d\n", bf, bc);

	return 0;
}