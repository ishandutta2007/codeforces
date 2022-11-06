#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

int n, m;
int a[500][500], b[500][500];
vector <int> sa[1001], sb[1001];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		scanf("%d", &a[i][j]);
		sa[i + j].push_back(a[i][j]);
	}
		
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		scanf("%d", &b[i][j]);
		sb[i + j].push_back(b[i][j]);
	}
	
	bool flag = true;
	for (int i = 0; i < n + m - 1; i++)
	{
		if (sa[i].size() != sb[i].size())
		{
			flag = false;
			break;
		}

		sort(sa[i].begin(), sa[i].end());
		sort(sb[i].begin(), sb[i].end());
		vector <int>::iterator ia, ib;
		for (ia = sa[i].begin(), ib = sb[i].begin(); ia != sa[i].end(); ia++, ib++)
		{
			if ((*ia) != (*ib))
			{
				flag = false;
				break;
			}
		}
	}

	if (flag) printf("YES");
	else printf("NO");
}