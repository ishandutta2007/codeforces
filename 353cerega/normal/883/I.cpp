#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

const int size1 = 4e5;
const int INF = 1e9;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	static int mas[size1];
	for (int i = 1; i <= n; i++)
	{
		cin >> mas[i];
	}
	sort(mas + 1, mas + n + 1);
	int l = -1, r = 1e9;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		static int pos[size1];
		pos[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			pos[i] = pos[i - 1];
			for (int j = pos[i - 1] + 1; j <= n; j++)
			{
				if (abs(mas[i] - mas[j]) > m)
				{
					break;
				}
				pos[i]++;
			}
			//cout << pos[i] << ' ' << m << endl;
		}
		static bool suf[size1];
		suf[n + 1] = true;
		static int suf1[size1];
		suf1[n + 1] = 1;
		for (int i = n; i >= 1; i--)
		{
			if (i + k > pos[i] + 1)
			{
				suf[i] = false;
				suf1[i] = suf1[i + 1];
				continue;
			}
			int per = suf1[i + k] - suf1[pos[i] + 2];
			if (per > 0)
			{
				suf[i] = true;
				suf1[i] = suf1[i + 1] + 1;
			}
			else
			{
				suf[i] = false;
				suf1[i] = suf1[i + 1];
			}
		}
		if (suf[1])
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	cout << r;
	return 0;
}