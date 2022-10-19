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
using lli = long long int;
using namespace std;
const int N = 4000010;
const int mod = 1000000;
lli a1, b1;
lli a, b, sm;
lli pat;
lli k;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> a1 >> b1;
	a = min(a1, b1);
	b = max(a1, b1);
	pat = a * b;
	sm = b - a;
	for (int i = 1; i <= sqrt(sm); i++)
	{
		if (sm % i == 0)
		{
			lli k1;
			k1 = (i - b % i) % i;
			if (pat > (a + k1) * (b + k1) / i)
			{
				pat = (a + k1) * (b + k1) / i;
				k = k1;
			}
			else if (pat == (a + k1) * (b + k1) / i && k1 < k) k = k1;
			int i1 = sm / i;
			k1 = (i1 - b % i1) % i1;
			if (pat > (a + k1) * (b + k1) / i1)
			{
				pat = (a + k1) * (b + k1) / i1;
				k = k1;
			}
			else if (pat == (a + k1) * (b + k1) / i1 && k1 < k) k = k1;
		}
	}
	//cout << pat << endl;
	cout << k;
	return 0;
}