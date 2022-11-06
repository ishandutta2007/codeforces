#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;
string GENOME = "ACTG";

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int arr[51][4];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int tmp = s[i] - GENOME[j];
			if (tmp < 0) tmp = -tmp;
			arr[i][j] = min(tmp, 26 - tmp);
		}
	}

	int result = 987654321;
	for (int i = 0; i <= n - 4; i++)
	{
		int tmp = arr[i][0] + arr[i + 1][1] + arr[i + 2][2] + arr[i + 3][3];
		result = min(result, tmp);
	}
	cout << result;
}