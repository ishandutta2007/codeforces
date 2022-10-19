#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 200000;

vector<int> t;
void ver(int x)
{
	t.clear();
	for(int i=2;i*i<=x;++i)
		if (x%i == 0)
		{
			t.push_back(i);
			while (x%i == 0)
				x /= i;
		}
	if (x > 1)
		t.push_back(x);
}

int n;
int a[N];

set<int> s;
bool stg(int x)
{
	ver(x);
	for (int i = 0; i < t.size(); ++i)
		if (s.find(t[i]) != s.end())
			return false;
	for (int i = 0; i < t.size(); ++i)
		s.insert(t[i]);
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i<n; ++i)
		cin >> a[i];
	bool z = false;
	int j = 2;
	for (int i = 0; i<n; ++i)
	{
		if (!z)
		{
			if (stg(a[i]))
			{
				cout << a[i] << ' ';
				continue;
			}
			else
			{
				for (int k = a[i]+1;; ++k)
					if (stg(k))
					{
						cout << k << ' ';
						break;
					}
				z = true;
			}
		}
		else
		{
			for (;;++j)
			{
				if (stg(j))
				{
					cout << j << ' ';
					break;
				}
			}
		}
	}
	return 0;
}