#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define auto char&

const int maxn = 3e2 + 20;
const int maxm = 1e6 + 20;

string s[maxn][maxn] , fs[maxn][maxn];

int sz[maxn][maxn] , ans;

int a[maxm] , b[maxm] , c[maxm] , d[maxm];

inline void operate(int i , int j , int x , int y)
{
	sz[i][j]--;
	sz[x][y]++;

	a[ans] = i;
	b[ans] = j;
	c[ans] = x;
	d[ans] = y;
	ans++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> s[i][j] , sz[i][j] = (int)s[i][j].size();

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> fs[i][j];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			reverse(s[i][j].begin() , s[i][j].end());

			for(auto ch : s[i][j])
			{
				if(ch == '1')
					operate(i , j , (i + (j == 0)) % n , 0);
				else
					operate(i , j , (i + (j == m - 1)) % n , m - 1);
			}
		}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			reverse(fs[i][j].begin() , fs[i][j].end());

	for(int i = 1; i < n; i++)
		for(int j = 0; j < 1; j++)
			while(sz[i][j] > 0)
				operate(i , j , 0 , 0);

	for(int i = 0; i < n - 1; i++)
		for(int j = m - 1; j < m; j++)
			while(sz[i][j] > 0)
				operate(i , j , n - 1 , m - 1);

	for(int i = 1; i < n - 1; i++)
		for(int j = 1; j < m - 1; j++)
			for(auto ch : fs[i][j])
			{
				if(ch == '1')
				{
					operate(0 , 0 , 0 , j);
					operate(0 , j , i , j);
				}
				else
				{
					operate(n - 1 , m - 1 , n - 1 , j);
					operate(n - 1 , j , i , j);
				}
			}

	for(int i = 0; i < 1; i++)
		for(int j = 1; j < m - 1; j++)
			for(auto ch : fs[i][j])
			{
				if(ch == '1')
					operate(0 , 0 , 0 , j);
				else
				{
					operate(n - 1 , m - 1 , 0 , m - 1);
					operate(0 , m - 1 , 0 , j);
				}
			}

	for(int i = n - 1; i < n; i++)
		for(int j = 1; j < m - 1; j++)
			for(auto ch : fs[i][j])
			{
				if(ch == '1')
				{
					operate(0 , 0 , n - 1 , 0);
					operate(n - 1 , 0 , n - 1 , j);
				}
				else
					operate(n - 1 , m - 1 , n - 1 , j);
			}

	for(int i = 1; i < n - 1; i++)
		for(int j = 0; j < 1; j++)
			for(auto ch : fs[i][j])
			{
				if(ch == '1')
				{
					operate(0 , 0 , i , 0);
				}
				else
				{
					operate(n - 1 , m - 1 , n - 1 , 0);
					operate(n - 1 , 0 , i , 0);
				}
			}

	for(int i = 1; i < n - 1; i++)
		for(int j = m - 1; j < m; j++)
			for(auto ch : fs[i][j])
			{
				if(ch == '1')
				{
					operate(0 , 0 , 0 , m - 1);
					operate(0 , m - 1 , i , m - 1);
				}
				else
					operate(n - 1 , m - 1 , i , m - 1);
			}

	// 2 * 2

	for(auto ch : fs[0][0])
	{
		if(ch == '1')
		{
			operate(0 , 0 , 0 , m - 1);
			operate(0 , m - 1 , 0 , 0);
		}
		else
		{
			operate(n - 1 , m - 1 , 0 , m - 1);
			operate(0 , m - 1 , 0 , 0);
		}
	}

	for(auto ch : fs[n - 1][m - 1])
	{
		if(ch == '1')
			operate(0 , 0 , 0 , m - 1);
		else
			operate(n - 1 , m - 1 , 0 , m - 1);

		operate(0 , m - 1 , n - 1 , m - 1);
	}

	for(auto ch : fs[0][m - 1])
	{
		if(ch == '1')
			operate(0 , 0 , 0 , m - 1);
		else
			operate(n - 1 , m - 1 , 0 , m - 1);
	}

	for(auto ch : fs[n - 1][0])
	{
		if(ch == '1')
			operate(0 , 0 , n - 1 , 0);
		else
			operate(n - 1 , m - 1 , n - 1 , 0);
	}

	cout << ans << endl;

	for(int i = 0; i < ans; i++)
		cout << a[i] + 1 << " " << b[i] + 1 << " " << c[i] + 1 << " " << d[i] + 1 << "\n";
}