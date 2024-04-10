#include <iostream>

#include <algorithm>

using namespace std;

long long a[100005];
int main()
{
	int n, k, j = 0;
	cin >> n;
	cin >> k;
	for(int i = 0; i < n ; i ++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	long long s = 0;
	for(int i = 0; i < k; i ++)
	{
		while(j < n && a[j] <= s)
		{
			j ++;
		}
		if(j < n)
		{
			a[j] -= s;
			s += a[j];
		}
		if(j < n && a[j] > 0)
		{
			cout << a[j] << endl;
			j ++;
		}
		else
		{
			cout << 0 << endl;
		}
	}
}