#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int maxk = 10;
int mod;

struct matrix
{
	int val[maxk][maxk];
	int n;
	matrix(int nn, int x = 0)
	{
		n = nn;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (i != j)
					val[i][j] = 0;
				else
					val[i][j] = x;
	}
	int* operator[] (int x)
	{
		return val[x];
	}
	matrix operator * (matrix b)
	{
		matrix ans(n, 0);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				for(int k=0; k<n; k++)
					ans[i][k] = (ans[i][k] + 1LL * val[i][j] * b[j][k]) % mod;
		return ans;
	}
	matrix operator + (matrix b)
	{
		matrix ans(n , 0);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				ans[i][j] = (val[i][j] + b[i][j]);
		return ans;
	}
};

matrix operator ^ (matrix a, ll b)
{
	matrix ans(a.n, 1);
	while(b)
	{
		if (b & 1)
			ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , x , y , dx , dy;
	ll t;
	cin >> n >> x >> y >> dx >> dy >> t;

	dx = (dx % n + n) % n , dy = (dy % n + n) % n;
	x-- , y--;
	mod = n;

	matrix b(6);
	b[0][0] = x;
	b[1][0] = y;
	b[2][0] = dx;
	b[3][0] = dy;
	b[4][0] = 0;
	b[5][0] = 1;

	matrix a(6);
	a[0][0] = 2 , a[0][1] = 1 , a[0][2] = 1 , a[0][3] = 0 , a[0][4] = 1 , a[0][5] = 2;
	a[1][0] = 1 , a[1][1] = 2 , a[1][2] = 0 , a[1][3] = 1 , a[1][4] = 1 , a[1][5] = 2;
	a[2][0] = 1 , a[2][1] = 1 , a[2][2] = 1 , a[2][3] = 0 , a[2][4] = 1 , a[2][5] = 2;
	a[3][0] = 1 , a[3][1] = 1 , a[3][2] = 0 , a[3][3] = 1 , a[3][4] = 1 , a[3][5] = 2;
	a[4][0] = 0 , a[4][1] = 0 , a[4][2] = 0 , a[4][3] = 0 , a[4][4] = 1 , a[4][5] = 1;
	a[5][0] = 0 , a[5][1] = 0 , a[5][2] = 0 , a[5][3] = 0 , a[5][4] = 0 , a[5][5] = 1;

	a = a ^ t;
	a = a * b;

	cout << a[0][0] + 1 << " " << a[1][0] + 1 << endl;
}