#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm> 
#include <string>
#include <queue>
using namespace std;

int n, m;
int board[1001][1001];

vector <int> rows[1001];
vector <int> cols[1001];

int b_search(vector <int> s, int num)
{

	int left = 0;
	int right = s.size()-1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		int value = s[mid];
		if (value > num)
		{
			right = mid - 1;
		}
		else if (value < num)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		int t;
		scanf("%d", &t);
		board[i][j] = t;
		rows[i].push_back(t);
		cols[j].push_back(t);

	}

	for (int i = 0; i < n; i++)
	{
	    sort(rows[i].begin(),rows[i].end());
	    rows[i].erase(unique(rows[i].begin(),rows[i].end()),rows[i].end());
	}
	for(int j=0;j<m;j++)
	{
	    sort(cols[j].begin(),cols[j].end());
	    cols[j].erase(unique(cols[j].begin(),cols[j].end()),cols[j].end());
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int row_size = rows[i].size();
			int col_size = cols[j].size();
			int row_pos = b_search(rows[i], board[i][j]);
			int col_pos = b_search(cols[j], board[i][j]);

			int L = max(row_pos, col_pos);
			int G = max((row_size - row_pos - 1), (col_size - col_pos - 1));
			int result = L + G + 1;
			printf("%d ", result);
		}
		printf("\n");
	}
		
}