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
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int n;
	string s;
	cin >> n >> s;

	bool flag = false;
	int a = 0, b = 0;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i - 1] > s[i])
		{
			flag = true;
			a = i - 1, b = i;
			break;
		}
	}

	if (!flag)
		cout << "NO";
	else
	{
		cout << "YES" << endl;
		cout << a+1 << ' ' << b+1;
	}
}