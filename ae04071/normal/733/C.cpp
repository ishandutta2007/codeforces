#include <cstdio>
#include <stack>
#include <vector>
#pragma warning (disable : 4996)

int arr[500];
int n;

int k, res[500];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) scanf("%d", res + i);

	std::vector<int> seg;
	seg.push_back(-1);

	bool flag = true, isDiff = false;
	int tsize = 0;
	int sum = 0, idx = 0, prev = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (idx == k) {
			flag = false;
			break;
		}

		sum += arr[i];
		tsize++;
		if (prev != arr[i])
		{
			isDiff = true;
		}
		if (sum > res[idx])
		{
			flag = false;
			break;
		}
		else if (sum == res[idx])
		{
			if (!isDiff && tsize != 1)
			{
				flag = false;
				break;
			}

			idx++;
			sum = 0;
			isDiff = false;
			tsize = 0;
			if (i != n - 1)
				prev = arr[i + 1];

			seg.push_back(i);
		}
	}

	if (idx != k) flag = false;

	if (flag)
	{
		printf("YES\n");
		for (int i = 1; i < seg.size(); i++)
		{
			int st = seg[i - 1] + 1, fi = seg[i];
			int max = -1, idx = -1;
			for (int j = st; j <= fi; j++)
			{
				if (max < arr[j])
				{
					if (max == -1)
					{
						if (arr[j] == arr[j + 1] && j + 1 <+fi) continue;
					}
					max = arr[j];
					idx = j;
				}
			}

			int s = seg[i - 1] + 1 - (i - 1);
			int temp = idx;
			if (idx - 1 >= st && arr[idx - 1] < arr[idx])
			{
				while (temp > st)
				{
					printf("%d L\n", temp - s + 1);
					temp--;
				}
				while (idx < fi)
				{
					printf("%d R\n", temp - s + 1);
					idx++;
				}
			}
			else
			{
				while (idx < fi)
				{
					printf("%d R\n", temp - s + 1);
					idx++;
				}
				while (temp > st)
				{
					printf("%d L\n", temp - s + 1);
					temp--;
				}
			}
		}
	}
	else
		printf("NO\n");


	return 0;
}