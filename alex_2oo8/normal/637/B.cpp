#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <iostream>

using namespace std;

int main ()
{
	cout.sync_with_stdio(false);
	string head = "@";
	string tail = "#";
	set<string> used;
	map<string, string> prev, next;
	prev[tail] = head;
	next[head] = tail;
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (used.find(s) != used.end())
		{
			next[prev[s]] = next[s];
			prev[next[s]] = prev[s];
		}
		else
		{
			used.insert(s);
		}
		prev[s] = head;
		next[s] = next[head];
		next[prev[s]] = s;
		prev[next[s]] = s;
	}
	string it = next[head];
	while (it != tail)
	{
		cout << it << endl;
		it = next[it];
	}
	return 0;
}