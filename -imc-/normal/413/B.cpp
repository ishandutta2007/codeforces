#include <cstdio>
#include <vector>

using namespace std;

const int maxN = 20050;
int a[maxN][11];

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			scanf("%d", &a[y][x]);

	vector<int> answer(n), sent(m);

	for (int i = 0; i < k; i++)
	{
		int sender, chat;
		scanf("%d %d", &sender, &chat);
		sender--; chat--;

		sent[chat]++;
		answer[sender]--;
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			answer[j] += sent[i] * a[j][i];

	for (int i = 0; i < n; i++)
		printf("%d ", answer[i]);
	printf("\n");

	return 0;
}