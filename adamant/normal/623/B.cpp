#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 42;
const int64_t inf = 1e18 + 42;
int64_t op[2][3][3][maxn];
int gc[2][3][3][maxn];
int x[maxn];
int64_t n, a, b;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void calc_dp(int t)
{
	for(int i = -1; i <= 1; i++)
		for(int j = -1; j <= 1; j++)
		{
			gc[t][i + 1][j + 1][0] = 0;
			op[t][i + 1][j + 1][0] = 0;
			gc[t][i + 1][j + 1][1] = x[0] + i;
			op[t][i + 1][j + 1][1] = a * abs(i);
			gc[t][i + 1][j + 1][2] = gcd(x[0] + i, x[1] + j);
			if(gc[t][i + 1][j + 1][2] > 1)
				op[t][i + 1][j + 1][2] = a * abs(i) + a * abs(j);
		}
	for(int i = 3; i <= n; i++)
	{
		for(int dx = -1; dx <= 1; dx++)
			for(int dy = -1; dy <= 1; dy++)
				for(int dz = -1; dz <= 1; dz++)
				{
					int G = gcd(gc[t][dx + 1][dy + 1][i - 1], x[i - 1] + dz);
					if(G > 1 || dz == 1)
					{
						if(G > 1) 
							op[t][dx + 1][dy + 1][i] = op[t][dx + 1][dy + 1][i - 1] + a * abs(dz);
						gc[t][dx + 1][dy + 1][i] = G;
						break;
					}
				}
	}
	
}

signed main()
{
	for(int x = 0; x < 2; x++)
		for(int y = 0; y < maxn; y++)
			for(int z = 0; z < 3; z++)
				for(int i = 0; i < 3; i++)
					op[x][z][i][y] = inf;
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a >> b;
	swap(a, b);
	for(int i = 0; i < n; i++)
		cin >> x[i];
	if(n == 1)
	{
		if(x[0] == 1)
			cout << b << "\n";
		else
			cout << 0 << "\n";
		return 0;
	}
	calc_dp(0);
	reverse(x, x + n);
	calc_dp(1);
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
		{
			reverse(gc[1][i][j], gc[1][i][j] + n + 1);
			reverse(op[1][i][j], op[1][i][j] + n + 1);
			for(int z = n + 1; z >= 1; z--)
			{
				op[1][i][j][z] = op[1][i][j][z - 1];
				gc[1][i][j][z] = gc[1][i][j][z - 1];
			}
		}
	int64_t ans = inf;
	int j[3][3][3][3] = {0};
	
	#ifdef LOCAL
	for(int i = 0; i <= n; i++)
	{
		for(int dx = 0; dx < 3; dx++)
			for(int dy = 0; dy < 3; dy++)
					cout << gc[0][dx][dy][i] << " \n"[dy == 2];
		cout << "\n";
	}
	cout << "===\n";
	for(int i = 0; i <= n; i++)
	{
		for(int dx = 0; dx < 3; dx++)
			for(int dy = 0; dy < 3; dy++)
				if(op[1][dx][dy][i] == inf)
					cout << -1 << " \n"[dy == 2];
				else
					cout << gc[1][dx][dy][i] << " \n"[dy == 2];
		cout << "\n";
	}
	#endif
	for(int i = 0; i <= n; i++)
		for(int dx = 0; dx < 3; dx++)
			for(int dy = 0; dy < 3; dy++)
			{
				op[0][dx][dy][i] += - 1LL * i * b;
				op[1][dx][dy][i] += 1LL * (i - 1) * b;
				if(i > 0)
				{
					op[0][dx][dy][i] = min(op[0][dx][dy][i], op[0][dx][dy][i - 1]);
					for(int dxx = 0; dxx < 3; dxx++)
						for(int dyy = 0; dyy < 3; dyy++)
						{
							while(j[dx][dy][dxx][dyy] < i && gcd(gc[0][dxx][dyy][j[dx][dy][dxx][dyy]], gc[1][dx][dy][i]) != 1)
								j[dx][dy][dxx][dyy]++;
							ans = min(ans, op[1][dx][dy][i] + op[0][dxx][dyy][j[dx][dy][dxx][dyy] - 1]);
						}
						ans = min(ans, op[0][dx][dy][i] + 1LL * n * b);
				}
			}
	cout << ans << "\n";
	return 0;
}