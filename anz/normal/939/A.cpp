#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> planes;
int main()
{
	planes.push_back(0);
	int n;
	cin >> n;
	while (n--)
	{
		int f;
		cin >> f;
		planes.push_back(f);
	}
	for (int i = 1; i < planes.size(); i++)
	{
		int a = planes[i];
		int b = planes[a];
		if (i == planes[b])
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}