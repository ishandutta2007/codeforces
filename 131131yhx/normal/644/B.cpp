#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll n, b, Q[400010], A[400010], B[400010], Ans[400010], t = 0, w = 1, Time = 0;

int main()
{
	scanf("%lld%lld", &n, &b);
	for(ll i = 1; i <= n; i++) scanf("%lld%lld", &A[i], &B[i]);
	for(ll i = 1; i <= n; i++)
		if(t < w && Time <= A[i])
		{
			Time = A[i] + B[i];
			Ans[i] = A[i] + B[i];
		}
		else
		{
			while(Time <= A[i] && w <= t)
			{
				Ans[Q[w]] = Time + B[Q[w]];
				Time += B[Q[w]];
				w++;
			}
			if(Time <= A[i]) Time = A[i];
			if(t + 1 - w < b) Q[++t] = i;
			else Ans[i] = -1;
		}
	while(t >= w) Ans[Q[w]] = (Time += B[Q[w]]), w++;
	for(ll i = 1; i <= n; i++) printf("%lld ", Ans[i]);
	return putchar('\n'), 0;
}