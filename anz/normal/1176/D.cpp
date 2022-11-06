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

vector <int> primes;
unordered_set<int> isPrime;
unordered_map<int, int> wt;

int main()
{
	primes.push_back(2);
	wt[2] = 1;
	int cnt = 2;
	for (int i = 3; i < 3000000; i+=2)
	{
		bool flag = true;
		for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
		{
			if (i%primes[j] == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			primes.push_back(i);
			isPrime.insert(i);
			wt[i] = cnt++;
		}
	}

	int n;
	multiset <int> arr;
	scanf("%d", &n);
	for(int i=0;i<n*2;i++)
	{
		int t;
		scanf("%d", &t);
		arr.insert(t);
	}

	vector <int> ans;
	while (!arr.empty())
	{
		int cur = *arr.rbegin();
		if (isPrime.count(cur) > 0)
		{
			ans.push_back(wt[cur]);
			arr.erase(arr.find(cur));
			arr.erase(arr.find(wt[cur]));
		}
		else
		{
			ans.push_back(cur);
			arr.erase(arr.find(cur));
			for (int i = 0; i < primes.size(); i++)
			{
				if (cur % primes[i] == 0)
				{
					arr.erase(arr.find(cur / primes[i]));
					break;
				}
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
}