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

class maxHeap
{
private:
	vector<int> arr;
	vector<int> resetArr;

	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }

public:
	int size() { return arr.size(); }
	void heapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int s = i;

		if (l < size() && arr[s] < arr[l])
			s = l;
		if (r < size() && arr[s] < arr[r])
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
		while (i != 0 && arr[i] > arr[parent(i)])
		{
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}
	int getMax() { return arr[0]; }
	int extractMax()
	{
		int ans = arr[0];
		arr[0] = arr[size() - 1];
		arr.pop_back();
		heapify(0);
		return ans;
	}
	void decrease(int x, int v)
	{
		arr[x] = v;
		heapify(x);
	}
	void set()
	{
		resetArr.resize(size());
		for (int i = 0; i < size(); i++)
		{
			resetArr[i] = arr[i];
		}
	}
	void reset()
	{
		arr.resize(resetArr.size());
		for (int i = 0; i < size(); i++)
		{
			arr[i] = resetArr[i];
		}
	}
};

int main()
{
	maxHeap H;
	ll x, k;
	cin >> x >> k;
	ll temp = x;
	for (int i = 0; temp > 0; i++)
	{
		if (temp & 1)
			H.insert(i);
		temp >>= 1;
	}
	
	if (k < H.size())
		cout << "No\n";
	else
	{
		cout << "Yes\n";
		H.set();
		while (k > H.size())
		{
			H.insert(H.getMax() - 1);
			H.decrease(0, H.getMax() - 1);
		}
		int ans = H.getMax();
		H.reset();
		while (H.getMax() != ans)
		{
			H.insert(H.getMax() - 1);
			H.decrease(0, H.getMax() - 1);
		}
		k -= H.size() - 1;
		while (H.size() > 1)
		{
			cout << H.extractMax() << ' ';
		}
		LoopR(i, H.getMax() - (k - 1), H.getMax())
		{
			cout << i << ' ';
		}
		cout << H.getMax() - (k - 1) << '\n';
	}
}