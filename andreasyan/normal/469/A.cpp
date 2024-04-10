#include <iostream>
using namespace std;

int a[102],b[102],p[102];
int main()
{
	int i, pat=0, k, n, m;
	cin >> n;
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> a[i];
		p[a[i]]++;
	}
	cin >> k;
	for (i = 0; i < k; i++)
	{
		cin >> b[i];
		p[b[i]]++;
	}
	for (i = 1; i <= n; i++)
	{
		if (p[i] > 0)
			pat++;
		else
			break;
	}
	if (pat == n)
		cout << "I become the guy." << endl;
	else
		cout << "Oh, my keyboard!" << endl;
	return 0;
}