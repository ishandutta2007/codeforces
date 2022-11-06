#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n;
deque<int> a;
int main()
{
	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	int result = 0;

	int curMost = 0;
	string s = "";
	while (!a.empty())
	{
		int left = a.front();
		int right = a.back();

		bool bl = left > curMost ? true : false;
		bool br = right > curMost ? true : false;

		if (bl && br)
		{
			if (left < right)
			{
				a.pop_front();
				curMost = left;
				s += 'L';
			}
			else
			{
				a.pop_back();
				curMost = right;
				s += 'R';
			}
			result++;
		}
		else if (bl)
		{
			a.pop_front();
			curMost = left;
			s += 'L';
			result++;
		}
		else if (br)
		{
			a.pop_back();
			curMost = right;
			s += 'R';
			result++;
		}
		else break;
	}

	cout << result << endl << s;
}