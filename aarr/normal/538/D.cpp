#include <iostream>
#include <vector>

using namespace std;

vector <int> x;
vector <int> y;
char c[55][55];
char a[105][105];
bool bpp[55][55];
bool bpn[55][55];
bool bnp[55][55];
bool bnn[55][55];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			cin >> c[i][j];
			if(c[i][j] == 'o')
			{
				x.push_back(i);
				y.push_back(j);
			}
			bpp[i][j] = true;
			bpn[i][j] = true;
			bnp[i][j] = true;
			bnn[i][j] = true;
		}
	}
	for(int i = 0; i < x.size(); i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			for(int k = 0; k < n; k ++)
			{
				if(x[i] + j < n && y[i] + k < n && c[x[i] + j][y[i] + k] == '.')
				{
					bpp[j][k] = false;
				}
				if(x[i] + j < n && y[i] - k >= 0 && c[x[i] + j][y[i] - k] == '.')
				{
					bpn[j][k] = false;
				}
				if(x[i] - j >= 0 && y[i] + k < n && c[x[i] - j][y[i] + k] == '.')
				{
					bnp[j][k] = false;
				}
				if(x[i] - j >= 0 && y[i] - k >= 0 && c[x[i] - j][y[i] - k] == '.')
				{
					bnn[j][k] = false;
				}
			}
		}
	}
	for(int i = 0; i < 2 * n - 1; i ++)
	{
		for(int j = 0; j < 2 * n - 1; j ++)
		{
			a[i][j] = '.';
		}
	}
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			if(bpp[i][j] == true)
			{
				a[n - 1 + i][n - 1 + j] = 'x';
			}
			if(bpn[i][j] == true)
			{
				a[n - 1 + i][n - 1 - j] = 'x';
			}
			if(bnp[i][j] == true)
			{
				a[n - 1 - i][n - 1 + j] = 'x';
			}
			if(bnn[i][j] == true)
			{
				a[n - 1 - i][n - 1 - j] = 'x';
			}
		}
	}
	bool e = true;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			if(c[i][j] == 'x')
			{
				bool d = false;
				for(int ii = 0; ii < n; ii ++)
				{
					for(int jj = 0; jj < n; jj ++)
					{
						if(bpp[ii][jj] == true && i - ii >= 0 && j - jj >= 0 && c[i - ii][j - jj] == 'o')
						{
							d = true;
						}
						if(bpn[ii][jj] == true && i - ii >= 0 && j + jj < n && c[i - ii][j + jj] == 'o')
						{
							d = true;
						}
						if(bnp[ii][jj] == true && i + ii < n && j - jj >= 0 && c[i + ii][j - jj] == 'o')
						{
							d = true;
						}
						if(bnn[ii][jj] == true && i + ii < n && j + jj < n && c[i + ii][j + jj] == 'o')
						{
							d = true;
						}
					}
				}
				if(d == false)
				{
					e = false;
				}
			}
		}
	}
	if(e == false)
	{
		cout << "NO";
	}
	else
	{
		a[n - 1][n - 1] = 'o';
		cout << "YES" << endl;
		for(int i = 0; i < 2 * n - 1; i ++)
		{
			for(int j = 0; j < 2 * n - 1; j ++)
			{
				cout << a[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}