#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string a;
	int n;
	cin >> n;
	cin >> a;
	vector <string> b;
	string c = "aa";
	for (int i = 0; i < n - 1; i++)
	{
		c[0] = a[i];
		c[1] = a[i + 1];
		b.push_back(c);
	}
	sort(b.begin(), b.end());
	int sum = 1, max = 0, index = 0;
	for (int i = 0; i < b.size()-1; i++)
	{
		if (b[i] == b[i + 1])
		{
			sum++;
		}
		else {
			if (sum > max)
			{
				max = sum;
				index = i;
			}
			sum = 1;
		}
	}
	if(sum > max)
	{
		max = sum;
		index = b.size()-1;
	}
	cout << b[index];
	return 0;
}