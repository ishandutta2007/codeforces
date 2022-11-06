#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int main()
{
	int n;
	string str;
	cin >> n >> str;
	list <char> l;
	for (int i = 0; i < str.length(); i++) l.push_back(str[i]);
	int cnt = 1;
	int ans = 0;
	for (auto i = l.begin(); i != l.end();)
	{
		if (cnt % 2)
		{
			auto j = i;
			j++;
			if (j == l.end())
			{
				i = l.erase(i);
				ans++;
				break;
			}
			else if((*j) == (*i))
			{
				i = l.erase(i);
				ans++;
			}
			else cnt++, i++;
		}
		else cnt++, i++;
	}
	cout << ans << endl;
	for (auto i = l.begin(); i != l.end(); i++)
		cout << (*i);
}