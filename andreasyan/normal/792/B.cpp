#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 105;

int n,k;
int b[N];
vector<int> a;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		a.push_back(i);
	}
	int i = 0;
	while (k--)
	{
		int x;
		cin >> x;
		int y = (i + x) % a.size();
		cout << a[y]+1 << ' ';
		a.erase(a.begin() + y);
		i = y;
	}
	cout << endl;
	return 0;
}