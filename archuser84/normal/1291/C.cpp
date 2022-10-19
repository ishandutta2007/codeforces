#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}

class minHeap
{
private:
	vector<int> arr;
	map<int, int> tracker;
	map<int, int> value;

	int size() { return arr.size(); }
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }

public:
	int getValue(int x) { return value[x]; }
	int getTrack(int x) { return tracker[x]; }
	void heapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int s = i;

		if (l < size() && value[arr[s]] > value[arr[l]])
			s = l;
		if (r < size() && value[arr[s]] > value[arr[r]])
			s = r;

		if (s != i)
		{
			swap(tracker[arr[i]], tracker[arr[s]]);
			swap(arr[i], arr[s]);
			heapify(s);
		}
	}
	void insert(int x, int v)
	{
		value[x] = v;
		tracker[x] = size();
		arr.push_back(x);
		int i = size() - 1;
		while (i != 0 && value[arr[i]] < value[arr[parent(i)]])
		{
			swap(tracker[arr[i]], tracker[arr[parent(i)]]);
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}
	int getMin() { return arr[0]; }
	int extractMin()
	{
		int ans = arr[0];
		arr[0] = arr[size() - 1];
		tracker[arr[0]] = 0;
		arr.pop_back();
		heapify(0);
		return ans;
	}
	void remove(int i)
	{
		int j = i;
		while (j != 0)
		{
			swap(tracker[arr[j]], tracker[arr[parent(j)]]);
			swap(arr[j], arr[parent(j)]);
			j = parent(j);
		}
		extractMin();
	}
};

int main()
{
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		int n, m, k;
		cin >> n >> m >> k;
		k = min(k, m - 1);
		int a[4000];
		Loop(i, 0, n)
			cin >> a[i];
		minHeap H;
		for (int i = n - 1; i >= k + (n - m); i--)
		{
			H.insert(i, max(a[i], a[i - (n - m)]));
		}
		int MAX = H.getValue(H.getMin());
		for (int i = k + (n - m) - 1; i >= (n - m); i--)
		{
			H.remove(H.getTrack(i + (m - k)));
			H.insert(i, max(a[i], a[i - (n - m)]));
			MAX = max(MAX, H.getValue(H.getMin()));
		}
		cout << MAX << '\n';
	}
}