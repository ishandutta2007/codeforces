#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

long long n, k;

typedef pair<long long, long long> P;
priority_queue< P > pq;
priority_queue<long long> lpq;

int main() {
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++)
	{
		long long t, b;
		scanf("%lld%lld", &t, &b);
		pq.push(make_pair(b,-t));
	}

	long long pleasure = 0;
	long long cSum = 0;
	for (int i = 0; i < n; i++)
	{
		long long b = pq.top().first;
		long long l = pq.top().second;
		cSum -= l;
		lpq.push(l);
		pq.pop();
		if (lpq.size() > k)
		{
			long long ers = lpq.top();
			cSum += ers;
			lpq.pop();
		}
		pleasure = max(pleasure, cSum*b);
	}
	printf("%lld", pleasure);
}