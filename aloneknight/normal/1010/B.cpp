#include<iostream>
 
using namespace std;
 
int ans[31];
 
void query(int l, int r, int ord, int len)
{
	if (l == r)
	{
		cout << l << endl;
		fflush(stdout);
		return;
	}
	int res;
	int m = (l + r) >> 1;
	cout << m << endl;
	fflush(stdout);
	cin >> res;
	if (res == 0)
		return;
	if (ans[ord%len] == -1)
		res = -res;
	if (res == -1)
		query(l, m, ord + 1, len);
	else
		query(m + 1, r, ord + 1, len);
}
 
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			cout << 1 << endl;
			fflush(stdout);
			cin >> ans[i];
			if (ans[i] == 0)
			{
				flag = false;
				break;
			}
			else if (ans[i] == -2)
				exit(0);
		}
		ans[0] = ans[n];
		if (flag)
			query(1, m, n + 1, n);
	}
	return 0;
}