#include <iostream>

#include <vector>

using namespace std;

int a[105];
int b[105];
vector <int> v;
int main()
{
	int n, k, s = 0;
	cin >> n;
	cin >> k;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		b[i] = i + 1;
	}
	for(int i = 0; i < n; i ++)
	{
		for(int j = 1; j < n; j ++)
		{
			if(a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				swap(b[j], b[j - 1]);
			}
		}
	}
	for(int i = 0; i < n; i ++)
	{
		if(s + a[i] <= k)
		{
			v.push_back(b[i]);
			s += a[i];
		}
	}
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i ++)
	{
		cout << v[i] << " ";
	}
	return 0;
}