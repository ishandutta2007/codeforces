#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int N = 3 * 100005;

int n, m, k;
char b[10];
bool c[N];
stack<int> a;
int main()
{
	int i, j;
	cin >> n;
	i = 1;
	for (j = 0; j<2 * n; ++j)
	{
		scanf("%s", &b);
		if (b[0] == 'a')
		{
			scanf("%d", &k);
			a.push(k);
		}
		else
		{
			if ((c[i] && a.empty()) || a.top() == i)
			{
				if(!c[i])
					a.pop();
			}
			else
			{
				while (!a.empty())
				{
					c[a.top()] = true;
					a.pop();
				}
				++m;
			}
			++i;
		}
	}
	cout << m << endl;
	return 0;
}