#include <algorithm>
#include <iostream>
using namespace std;
int a[101], b[101];
int poqb(int a, int b)
{
	int i = 0;
	while ((a+i) % b != 0)
	{
		i++;
	}
	return a + i;
}
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[a[i]]--;
	}
	sort(b, b + 101);
	int c = -1 * b[0];
	int pat = 0;
	int i = 0, sm = poqb(c, k);
	while (b[i] != 0)
	{
		b[i] *= -1;
		pat += sm - b[i];
		i++;
	}
	cout << pat;
    return 0;
}