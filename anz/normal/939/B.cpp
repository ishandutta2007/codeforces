#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	long long n, k;
	cin >> n >> k;

	long long mx = 0, result = 0, type = 1;
	for (int i = 0; i < k; i++)
	{
		long long tmp;
		cin >> tmp;
		long long cap = (n / tmp)*tmp;
		if (cap > mx)
		{
			mx = cap;
			result = (n / tmp);
			type = i + 1;
		}
	}
	cout << type << ' ' << result;
}