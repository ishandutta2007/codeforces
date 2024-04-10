#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int N, K;
double p[100];
double dp[1048576];
double ans[100];
int loga[524289];


int solve()
{

	dp[0] = 1.0;
	int arr[202];
	for (int i = 1; i<(1 << N); i++)
	{
		dp[i] = 0;
		int tp = 0;
		for (int x = i; x; x -= x&(-x))
			arr[tp++] = loga[x&(-x)];
		double sump = 0;
		for (int j = 0; j<tp; j++)
			sump += p[arr[j]];
		double etc = 1 - sump;
		for (int j = 0; j<tp; j++)
			dp[i] += dp[i - (1 << arr[j])] * p[arr[j]] / (p[arr[j]] + etc);
		if (tp == K)
			for (int j = 0; j<tp; j++)
				ans[arr[j]] += dp[i];
	}
	return 0;
}

double rans[1020];
int main()
{
	int NN, KK;
	scanf("%d%d", &NN, &KK);
	double px[1010];
	vector<pair<double, int> > v;
	int tp = 0;
	for (int i = 0; i<NN; i++)
	{
		scanf("%lf", px + i);
	//	printf("%d\n", px[i]>0.0001);
		if (px[i] > 0.0001)
		{
			v.push_back(make_pair(px[i], i));
			p[tp++] = px[i];
		}
	}
	N = v.size();
	K = min(N, KK);
	for (int i = 0; i<N; i++) loga[1 << i] = i;
	solve();
	for (int i = 0; i<N; i++)
	{
		rans[v[i].second] = ans[i];
	}
	for (int i = 0; i < NN; i++)
		printf("%.12f ", rans[i]);
	return 0;
}