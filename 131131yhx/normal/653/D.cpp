#include <bits/stdc++.h>
#define M 2010
#define Inf 1000000000000000ll

using namespace std;

typedef long long ll;

ll n, m, k, L[M], R[M], S[M];

ll Head[201], Next[M], Go[M], Val[M], Cnt = 1;

ll H[201], Now[201], Pre[201], Flow[201], Amount[201];

inline void addedge(int x, int y, int z)
{
	Go[++Cnt] = y;
	Val[Cnt] = z;
	Next[Cnt] = Head[x];
	Head[x] = Cnt;
}

bool Max_flow()
{
	ll i = 1, getans, c = Inf, T, ans = 0;
	Amount[0] = n;
	while(H[i] <= n)
	{
		getans = 0;
		for((T = (Now[i]) ? Now[i] : Head[i]); T; T = Next[T])
			if(Val[T] && H[Go[T]] == H[i] - 1)
			{
				Flow[i] = c;
				getans = 1, c = min(c, Val[T]);
				Pre[Go[T]] = T ^ 1;
				Now[i] = T;
				i = Go[T];
				if(i == n)
				{
					ans += c;
					while(i != 1)
					{
						Val[Pre[i]] += c;
						Val[Pre[i] ^ 1] -= c;
						i = Go[Pre[i]];
					}
					c = Inf;
				}
				break;
			}
		if(!getans)
		{
			ll Min = n, v = 0;
			for(ll T = Head[i]; T; T = Next[T])
				if(Val[T] && H[Go[T]] < Min)
				{
					Min = H[Go[T]];
					v = T;
				}
			Now[i] = v;
			if(--Amount[H[i]] == 0) break;
			Amount[H[i] = Min + 1]++;
			if(i != 1) i = Go[Pre[i]], c = Flow[i];
		}
	}
	return ans >= k;
}
bool Pend(double val)
{
	memset(Head, 0, sizeof Head);
	memset(H, 0, sizeof H);
	memset(Now, 0, sizeof Now);
	memset(Pre, 0, sizeof Pre);
	memset(Flow, 0, sizeof Flow);
	memset(Amount, 0, sizeof Amount);
	Cnt = 1;
	for(ll i = 1; i <= m; i++)
	{
		addedge(L[i], R[i], min(k + 5, (ll)floor((double) S[i] / val + 1e-12)));
		addedge(R[i], L[i], 0);
	}
	return Max_flow();
}

int main()
{
	scanf("%lld%lld%lld", &n, &m, &k);
	for(ll i = 1; i <= m; i++) scanf("%d%d%d", &L[i], &R[i], &S[i]);
	double ans;
	for(double l = 0.0, r = 1000000.0; l * (1 + 1e-15) <= r;)
	{
		double Mid = (l + r) / 2;
		if(Pend(Mid)) ans = Mid, l = Mid; else r = Mid;
	}
	printf("%.12lf\n", ans * k);
	return 0;
}