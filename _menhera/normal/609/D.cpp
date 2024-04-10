#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

int N, M, K, S;
int A[MAXN], B[MAXN], T[MAXN], C[MAXN];

bool can(int d)
{
	int a = *min_element(A, A+d), b = *min_element(B, B+d);
	vector<long long> V;
	for(int i=0; i<M; ++i)
		if(T[i] == 1) V.push_back(1LL*a*C[i]);
		else V.push_back(1LL*b*C[i]);
	sort(V.begin(), V.end());
	long long s = 0;
	for(int i=0; i<K; ++i) s += V[i];
	return s <= S;
}

int main()
{
	scanf("%d%d%d%d", &N, &M, &K, &S);
	for(int i=0; i<N; ++i) scanf("%d", A+i);
	for(int i=0; i<N; ++i) scanf("%d", B+i);
	for(int i=0; i<M; ++i) scanf("%d%d", T+i, C+i);
	int lo = 0; // impos
	int hi = N+1; // pos
	while(lo+1!=hi)
	{
		int mi = (lo+hi)/2;
		if(can(mi)) hi = mi;
		else lo = mi;
	}
	if(hi == N+1) puts("-1");
	else
	{
		printf("%d\n", hi);
		int d_a = min_element(A, A+hi)-A;
		int d_b = min_element(B, B+hi)-B;
		vector<pair<long long, int> > V;
		for(int i=0; i<M; ++i)
			if(T[i] == 1) V.emplace_back(1LL*A[d_a]*C[i], i);
			else V.emplace_back(1LL*B[d_b]*C[i], i);
		sort(V.begin(), V.end());
		for(int i=0; i<K; ++i)
		{
			printf("%d ", 1+V[i].second);
			if(T[V[i].second] == 1) printf("%d\n", 1+d_a);
			else printf("%d\n", 1+d_b);
		}
	}
}