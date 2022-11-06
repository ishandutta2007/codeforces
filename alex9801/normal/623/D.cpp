#include <stdio.h>
#include <queue>
#include <algorithm>

int arr[100];

struct str
{
	str(int as = 0, double ac = 0.0, double aqn = 0.0, double aq = 0.0) :s(as), c(ac), qn(aqn), q(aq)
	{
	}
	int s;
	double c;
	double qn;
	double q;
	bool operator <(const str &x) const
	{
		return c < x.c;
	}
};

std::priority_queue<str> pq;

int main()
{
	str top;
	int n, c, i, j;
	double p, q, t, p1, p2 = 1.0, r;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
		scanf("%d", &arr[i]);

	std::sort(arr, arr+n);

	c = 0;
	for(i = 0; i<n; i++)
	{
		c++;
		if(i==n-1||arr[i]!=arr[i+1])
		{
			p = arr[i]/100.0;
			q = 1-p;
			t = q*q;
			pq.push(str(c, (1-t)/p, t, q));
			while(c)
			{
				c--;
				p2 *= p;
			}
		}
	}

	r = p2*n;
	i = n+1;

	while(i<n+300000)
	{
		top = pq.top();
		pq.pop();

		for(j = 0; j<top.s; i++, j++)
		{
			p1 = p2*top.c;
			r += (p1-p2)*i;
			p2 = p1;
		}

		top.c = (1.0 - top.qn*top.q)/(1.0 - top.qn);
		top.qn *= top.q;

		pq.push(top);
	}

	printf("%.10lf", r);
	return 0;
}