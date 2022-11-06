#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

struct str
{
	long long t, w;
	str(long long at = 0, long long aw = 0) :t(at), w(aw) {}
	bool operator <(const str& a) const
	{
		return t > a.t;
	}
};

str arr[300000];
std::priority_queue<long long> pq;

int main()
{
	int n, s = 0, p, r, i;
	long long x, t, w;
	scanf("%d", &n);
	scanf("%lld%*lld", &x);
	for(i = 1; i<n; i++)
	{
		scanf("%lld%lld", &t, &w);
		w -= t-1;
		if(t > x)
			pq.push(-w);
		else
			arr[s++] = str(t, w);
	}

	std::sort(arr, arr+s);

	r = pq.size()+1;
	p = 0;

	while(!pq.empty() && x>=0)
	{
		x -= -pq.top();
		pq.pop();

		if(x<0)
			break;

		while(p<n && arr[p].t>x)
			pq.push(-arr[p++].w);

		r = std::min(r, (int)pq.size()+1);
	}

	printf("%d", r);
	return 0;
}