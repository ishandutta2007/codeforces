#include <iostream>
using namespace std;
int b[100001], b2[100001];


int main()
{
	int n, l, a;
	cin >> n >> l >> a;
	int b1, pat = 0;
	if (n == 0)
		cout << l / a;
	else {
		cin >> b1 >> b[0];
		b2[0] = b1;
		b[0] += b1;
		pat += (b2[0] / a);
		b2[0] = b[0];
		for (int i = 1; i < n; i++)
		{
			cin >> b1 >> b[i];
			b2[i] = b1 - b[i - 1];
			b[i] += b1;
			pat += (b2[i] / a);
			b2[i]=b[i];
		}
		pat += ((l - b2[n - 1]) / a);
		cout << pat;
	}
	return 0;
}