#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <list>

using namespace std;

int n, k;

int a[200001];
int wh[200001];
int cache[200001];

struct myPair {
	int first;
	list<int>::iterator second;

	bool operator<(const myPair a) const
	{
		return first < a.first;
	}
};

list <int> l;

priority_queue<myPair> pq;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		l.push_back(a[i]);
		wh[a[i]] = i;
		list<int>::iterator it = l.end();
		it--;
		myPair tmp;
		tmp.first = a[i], tmp.second = it;
		pq.push(tmp);
	}

	int whatTeam = 1;
	while (!pq.empty())
	{
		int curNum = pq.top().first;
		if (!cache[wh[curNum]])
		{
			cache[wh[curNum]] = whatTeam;
			list<int>::iterator it = pq.top().second;
			
			list<int>::iterator left = it;
			for (int i = 0; i < k; i++)
			{
				if (left == l.begin()) break;
				left--;
				cache[wh[*(left)]] = whatTeam;
			}

			list<int>::iterator right = it;
			for (int i = 0; i < k; i++)
			{
				right++;
				if (right == l.end()) break;
				cache[wh[*(right)]] = whatTeam;
			}

			if (right != l.end()) right++;
			l.erase(left, right);

			whatTeam = 3 - whatTeam;
		}
		pq.pop();
	}

	for (int i = 1; i <= n; i++)
		printf("%d", cache[i]);
}