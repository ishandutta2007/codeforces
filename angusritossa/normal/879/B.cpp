#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
queue<ll> q;
ll mx;
int main()
{
	scanf("%I64d%I64d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		ll p;
		scanf("%I64d", &p);
		mx = max(mx, p);
		q.push(p);
	}
	if (k > n)
	{
		printf("%I64d\n", mx);
		return 0;
	}
	pair<ll, ll> playing;
	playing.first = q.front();
	q.pop();
	playing.second = q.front();
	q.pop();
	int currentwins = 0;
	while (true)
	{
		if (playing.first < playing.second) { swap(playing.first, playing.second); currentwins = 0; }
		currentwins++;
		q.push(playing.second);
		playing.second = q.front();
		q.pop();
		if (currentwins >= k)
		{
			printf("%I64d\n", playing.first);
			break;
		}
	}
}