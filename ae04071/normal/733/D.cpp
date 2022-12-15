#include <cstdio>
#include <algorithm>
#include <functional>

inline int Max(int a, int b)
{
	return (a > b) ? a : b;
}

inline int Min(int a, int b)
{
	return (a < b) ? a : b;
}

inline void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

inline int Min(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c) return a;
		else return c;
	}
	else
	{
		if (b < c) return b;
		else return c;
	}
}

struct Block
{
	int r[3];
	int idx;
	
	Block() {
		for (int i = 0; i < 3; i++)
			r[i] = 0;
	}
	Block(int a, int b, int c, int _idx) : idx(_idx)
	{
		if (a < b) Swap(a, b);
		if (b < c) Swap(b, c);
		if (a < b) Swap(a, b);
		r[0] = a, r[1] = b, r[2] = c;
	}
};

int n;
Block arr[100010];

bool cmp(const Block &b1, const Block &b2)
{
	for (int i = 0; i < 3; i++)
	{
		if (b1.r[i] != b2.r[i]) return b1.r[i] > b2.r[i];
	}
	return b1.r[2] > b2.r[2];
}

int main()
{
	scanf("%d", &n);
	
	int a, b, c;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		arr[i] = Block(a, b, c, i);
	}
	
	std::sort(arr, arr + n, cmp);

	int size = 0, maxLen = -1;
	int ord[2];
	
	for (int i = 0; i < n; i++)
	{
		if (arr[i].r[2] > maxLen)
		{
			maxLen = arr[i].r[2];
			size = 1;
			ord[0] = arr[i].idx;
		}
		if (i == n - 1) continue;
		if (arr[i].r[0] == arr[i + 1].r[0] && arr[i].r[1] == arr[i + 1].r[1])
		{
			int l = Min(arr[i].r[0], arr[i].r[1], arr[i].r[2] + arr[i + 1].r[2]);
			if (l > maxLen)
			{
				maxLen = l;
				size = 2;
				ord[0] = arr[i].idx, ord[1] = arr[i + 1].idx;
			}
		}
	}

	if (size == 2)
	{
		if (ord[0] > ord[1])
			Swap(ord[0], ord[1]);
	}

	printf("%d\n", size);
	for (int i = 0; i < size; i++)
		printf("%d ", ord[i] + 1);

	return 0;
}