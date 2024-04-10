#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

class minHeap
{
private:
	vector<int> arr;

	int size() { return arr.size(); }
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }

public:
	void heapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int s = i;

		if (l < size() && arr[s] > arr[l])
			s = l;
		if (r < size() && arr[s] > arr[r])
			s = r;

		if (s != i)
		{
			swap(arr[i], arr[s]);
			heapify(s);
		}
	}
	void insert(int x)
	{
		arr.push_back(x);
		int i = size() - 1;
		while (i != 0 && arr[i] < arr[parent(i)])
		{
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}
	int getMin() { return arr[0]; }
	int extractMin()
	{
		if (size() == 0)
			return -1;
		int ans = arr[0];
		arr[0] = arr[size() - 1];
		arr.pop_back();
		heapify(0);
		return ans;
	}
};

int main()
{
	minHeap h;
	int n; ll k;
	int x[100000];
	ll ans = 0;
	cin >> n >> k;
	Loop(i, 0, n)
		cin >> x[i];
	int a;
	cin >> a;
	Loop(i, 0, n)
	{
		int c;
		cin >> c;
		h.insert(c);
		while (k < x[i])
		{
			int min = h.extractMin();
			if (min == -1)
			{
				ans = -1;
				goto end;
			}
			k += a;
			ans += min;
		}
	}
end:
	cout << ans << '\n';
}