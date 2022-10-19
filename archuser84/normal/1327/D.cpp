#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 200000;
const int logN = 18;
int p[N];
int c[N];
int n;
bool visited[N];
int go[N][logN];

void pre()
{
	Loop(i, 0, n)
		go[i][0] = p[i];
	Loop(x, 1, logN)
	{
		Loop(i, 0, n)
			go[i][x] = go[go[i][x - 1]][x - 1];
	}
}

int Go(int s, int j)
{
	for (int i = 0; j > 0; i++)
	{
		if (j & 1)
			s = go[s][i];
		j >>= 1;
	}
	return s;
}

bool Can(int s, int j)
{
	int i = s;
	do
	{
		i = Go(i, j);
		if (c[i] != c[s])
			return false;
	} while (i != s);
	return true;
}

int subSolve(int s, int k)
{
	int miin = 10000000;
	for (int i = 1; i * i <= k; i++)
	{
		if (miin <= i)
			break;
		if (k % i)
			continue;
		int x = s;
		Loop(_, 0, i)
		{
			if (Can(x, i))
			{
				miin = i;
				break;
			}
			x = p[x];
		}
		int r = k / i;
		if (miin <= r || i == r)
			continue;
		x = s;
		Loop(_, 0, r)
		{
			if (Can(x, r))
			{
				miin = r;
				break;
			}
			x = p[x];
		}
	}
	return miin;
}

int Solve()
{
	memset(visited, 0, n);
	int miin = 10000000;
	Loop(i, 0, n)
	{
		if (visited[i])
			continue;
		int k = 0;
		int j = i;
		while (!visited[j])
		{
			visited[j] = true;
			k++;
			j = p[j];
		}
		miin = min(miin, subSolve(i, k));
	}
	return miin;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		Loop(i, 0, n)
		{
			cin >> p[i];
			p[i]--;
		}
		Loop(i, 0, n)
			cin >> c[i];
		pre();
		cout << Solve() << '\n';
	}
}