#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 1010;
int n, m;
int L;
int s, t;
int unknown = 0;
const int inf = 1 << 30;
vector<pii> A[N];
vector<pii> unknowns;
vector<pair<pii, int>> knowns;
ll d[N];

class minHeap
{
private:
	vector<int> arr;
	int tracker[N];
	ll value[N] = {};

	int size() { return arr.size(); }
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }

public:
	ll getValue(int x) { return value[x]; }
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
	void insert(int x, ll v)
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
	void Decrease(int x, ll v)
	{
		value[x] = v;
		int i = tracker[x];
		while (i != 0 && value[arr[i]] < value[arr[parent(i)]])
		{
			swap(tracker[arr[i]], tracker[arr[parent(i)]]);
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}
	bool empty()
	{
		return !size();
	}
};

int lni = 0;
int vol = 1;
int getW(int x)
{
	if (x >= 0)
		return x;
	x = ~x;
	if (x < lni)
		return inf;
	if (x == lni)
		return vol;
	if (x > lni)
		return 1;
}

void dij(int s)
{
	memset(d, -1, sizeof(d)); d[s] = 0;
	minHeap H;
	H.insert(s, 0);
	while (!H.empty())
	{
		int u = H.extractMin();
		for (pii e : A[u])
		{
			int v = e.first;
			ll w = d[u] + getW(e.second);
			if (d[v] == -1)
			{
				d[v] = w;
				H.insert(v, w);
			}
			else if (d[v] > w)
			{
				d[v] = w;
				H.Decrease(v, w);
			}
		}
	}
}

void bin()
{
	int l = 0, r = unknown - 1;
	while (l < r)
	{
		int m = (l + r + 1) / 2;
		lni = m;
		dij(s);
		if (d[t] <= L)
			l = m;
		else
			r = m - 1;
	}
	lni = l;
}

int getvol()
{
	vol = inf;
	dij(unknowns[lni].first);
	ll sa = d[s], ta = d[t];
	dij(unknowns[lni].second);
	ll sb = d[s], tb = d[t];
	ll ans = min(sa + tb, sb + ta);
	vol = L - ans;
	return vol;
}

int main()
{
	FAST;
	cin >> n >> m >> L >> s >> t;
	Loop(i, 0, m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (w == 0)
		{
			w = ~unknown++;
			unknowns.push_back({ u,v });
		}
		else
		{
			knowns.push_back({ { u,v }, w });
		}
		A[u].push_back({ v,w });
		A[v].push_back({ u,w });
	}
	ll miin, maax;
	lni = 0; dij(s); miin = d[t];
	lni = unknown; dij(s); maax = d[t];
	if (!(miin <= L && L <= maax))
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	if (unknown)
	{
		if (maax > L)
		{
			bin();
			Loop(i, 0, lni)
				cout << unknowns[i].first << ' ' << unknowns[i].second << ' ' << inf << '\n';
			cout << unknowns[lni].first << ' ' << unknowns[lni].second << ' ' << getvol() << '\n';
			Loop(i, lni + 1, unknown)
				cout << unknowns[i].first << ' ' << unknowns[i].second << ' ' << 1 << '\n';
		}
		else
		{
			Loop(i, 0, unknown)
				cout << unknowns[i].first << ' ' << unknowns[i].second << ' ' << inf << '\n';
		}
	}
	Loop(i,0,m-unknown)
		cout << knowns[i].first.first << ' ' << knowns[i].first.second << ' ' << knowns[i].second << '\n';
}