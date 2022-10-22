#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 505;
long long weight[maxN][maxN];

int index[maxN];
bool open[maxN];
vector <long long> answer;

int main()
{
	int N;
	scanf ("%i", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf ("%lld", &weight[i][j]);

	for (int i = 0; i < N; i++)
	{
		scanf ("%i", &index[i]);
		index[i]--;
	}

	for (int t = N - 1; t >= 0; t--)
	{
		int v = index[t];
		long long sum = 0;
		open[v] = true;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (weight[i][v] + weight[v][j] < weight[i][j])
					weight[i][j] = weight[i][v] + weight[v][j];

				if (open[i] && open[j])
					sum += weight[i][j];
			}

		answer.push_back (sum);
	}

	for (int i = N - 1; i >= 0; i--)
		printf ("%lld ", answer[i]);
	printf ("\n");

	return 0;
}