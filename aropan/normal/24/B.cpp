#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1111;
const int MAXM = 55;
const int P[11] = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

map <string, int> M;
string name[MAXN];
int d[MAXN][MAXM];
int k, c, n;
int a[MAXN];

bool check(const int &i, const int &j)
{
	for (int z = 0; z < MAXM; z++)
		if (d[i][z] != d[j][z])
			return d[i][z] > d[j][z];
	return false;
}

int main()
{
	/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/

    cin >> k;
    memset(d, 0, sizeof(d));
    M.clear();
    n = 0;
    while (k--)
    {
		cin >> c;
		for (int i = 1; i <= c; i++)
		{
			string s;
			int x;
			
			cin >> s;
			
			if (M[s] == 0)
			{
				n++;
				M[s] = n;
				name[n] = s;
			}
			x = M[s];
			
			if (i <= 10)
				d[x][0] += P[i];
				
			d[x][i]++;
		}
	}
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
		
	partial_sort(a, a, a + n, check);
	cout << name[a[0]] << endl;
	
	for (int i = 1; i <= n; i++) swap(d[i][0], d[i][1]);

	partial_sort(a, a, a + n, check);
	cout << name[a[0]] << endl;
    return 0;
}