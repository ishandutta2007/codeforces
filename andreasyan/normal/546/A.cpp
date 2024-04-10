#include <iostream>
using namespace std;

int main()
{
	int k, n, w, i, j,pat=0;
	cin >> k >> n >> w;
	for (i = 1; i <= w; i++)
	{
		if (n - k*i >= 0)
			n = n - k*i;
		else
			pat += k*i;
	}
	if (pat == 0)
	{
		cout << pat << endl;
		return 0;
	}
	cout << pat - n << endl;
	return 0;
}