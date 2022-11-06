#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
string a;
int main()
{
	cin >> a;

	vector <int> cut;

	int index = 0;
	int count_0 = 0;
	int count_1 = 0;
	vector <int> zeros;
	for (index; index < a.length(); index++)
	{
		if (a[index] == '0') count_0++;
		if (a[index] == '1') count_1++;
		if (a[index] == '2')
		{
			cut.push_back(index);
			zeros.push_back(count_0);
			count_0 = 0;
		}
	}
	zeros.push_back(count_0);

	for (int i = 0; i < zeros[0]; i++) cout << '0';
	for (int i = 0; i < count_1; i++) cout << '1';

	for (int i = 0; i < cut.size(); i++)
	{
		cout << '2';
		for (int j = 0; j < zeros[i + 1]; j++) cout << '0';
	}
}