#include <iostream>

int N;

void shift(int id, int arr[])
{
  if(arr[id] != -1)
  {
    arr[2*id] = arr[2*id + 1] = arr[id];
    arr[id] = -1;
  }
}

int get(int x, int arr[], int id = 1, int l = 0, int r = N)
{
  if(l == r)
    return arr[id];

  shift(id, arr);
  int m = (l+r)/2;
  if(m >= x)
    return get(x, arr, 2*id, l, m);
  else
    return get(x, arr, 2*id + 1, m+1, r);
}

void update(int x, int y, int val, int arr[], int id = 1, int l = 0, int r = N)
{
  if(x <= l && r <= y)
  {
    arr[id] = val;
    return;
  }

  if(r < x || y < l)
    return;

  shift(id, arr);
  int m = (l+r)/2;
  update(x, y, val, arr, 2*id, l, m);
  update(x, y, val, arr, 2*id + 1, m+1, r);
}

int main()
{
	std::ios::sync_with_stdio(false);

	int M;
	std::cin >> N >> M;

	long long a[N+1], b[N+1];
	for(int i = 0; i < N; i++)
		std::cin >> a[i+1];

	for(int i = 0; i < N; i++)
		std::cin >> b[i+1];

	int root[3*N], link[3*N];
	for(int i = 0; i < 3*N; i++)
		root[i] = link[i] = -1;

	int t, x, y, k;
	while(M--)
	{
		std::cin >> t;
		if(t == 1)
		{
			std::cin >> x >> y >> k;
			update(y, y+k-1, y, root);
			update(y, y+k-1, x, link);
		}
		else
		{
			std::cin >> x;
			int curRoot = get(x, root);
			if(curRoot == -1)
				std::cout << b[x]  << std::endl;
			else
			{
				int curLink = get(x, link);
				std::cout << a[x - curRoot + curLink] << std::endl;
			}
		}
	}

	return 0;
}