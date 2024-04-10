#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
int n, k, sm[200001];
char km[200001];
lli sum;
priority_queue <int> a;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> sm[i];
	}
	cin >> km[0];
	a.push(sm[0]);
	for (int i = 1; i < n; i++)
	{
		cin >> km[i];
		while (i < n && km[i] == km[i - 1])
		{
			a.push(sm[i]);
			i++;
			if (i == n) break;
			cin >> km[i];
		}
		int k1 = k;
		while (k1-- && !a.empty())
		{
			sum += a.top();
			a.pop();
		}
		if (i >= n)
		{
			cout << sum;
			return 0;
		}
		a = priority_queue <int>();
		a.push(sm[i]);
	}
	if (!a.empty())
		sum += sm[n - 1];
	cout << sum;
	return 0;
}