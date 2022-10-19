#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <stack>
#include <set>
typedef long long int lli;
using namespace std;

	string s;
	vector<lli> r, l;
int main()
{
	std::ios::sync_with_stdio(false);
	

	cin >> s;
	lli i, curp = 1, j;
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] == 'r')
		{
			r.push_back(i + 1);
		}
		else
		{
			l.push_back(i + 1);
		}
	}
	cout << endl;
	for (int i = 0; i < r.size(); i++)
	{
		cout << r[i] << "\n";
	}
	cout << endl;
	for (int i = l.size() - 1; i >= 0; i--)
	{
		cout << l[i] << "\n";
	}
	cout << endl;
	return 0;
}