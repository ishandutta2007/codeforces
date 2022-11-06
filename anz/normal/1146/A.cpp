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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'a') cnt++;
	cout << min(cnt * 2 - 1, (int)s.length());
}