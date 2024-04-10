#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int maxN = 5100;

int d[maxN][maxN];
int zf[maxN][maxN];
char sb[maxN * 3];

int nn;
	
void z_function (int offset) {
	int n = nn - offset;
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			zf[offset][i+offset] = min (r-i+1, zf[offset][i-l+offset]);
		while (i+zf[offset][i+offset] < n && sb[offset+zf[offset][i+offset]] == sb[offset+i+zf[offset][i+offset]])
			++zf[offset][offset+i];
		if (i+zf[offset][offset+i]-1 > r)
			l = i,  r = i+zf[offset][offset+i]-1;
	}
}

const int MOD = 1e9 + 7;

void add(int& x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main()
{
	scanf("%d %s", &nn, sb);
	
	string s = sb;
	
	for (int l = 0; l < nn; l++)
	{
		z_function(l);
	}
	
	d[1][1] = 1;
	
	int answer = 0;
	for (int n = 1; n <= nn; n++)
		for (int k = 1; k <= n; k++)
		{
			if (d[n][k] == 0) continue;
			
			//printf("d[%d][%d] is %d, ", n, k, d[n][k]);
			
			if (n == nn)
			{
				add(answer, d[n][k]);
				continue;
			}
			
			add(d[n + 1][k + 1], d[n][k]);
			
			int common = zf[n - k][n];
			//printf("common %d\n", common);
			if (common < k && sb[n - k + common] < sb[n + common])
				common = k;
			else
				common = k + 1;
			
			if (sb[n] == '0') continue;
			
			//printf("  += to d[%d][%d]\n", n + common, common);
			if (n + common <= nn)
				add(d[n + common][common], d[n][k]);
		}
		
	printf("%d\n", answer);
	
	return 0;
}