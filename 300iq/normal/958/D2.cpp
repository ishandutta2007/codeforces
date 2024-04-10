#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

struct modt
{
	int me;
	modt(int me)
		: me(me)
	{}
	modt() : me(0){}
	modt operator +(modt b)
	{
		int mem = me + b.me;
		if (mem >= mod)
			mem -= mod;
		return mem;
	}
	modt operator -(modt b)
	{
		int mem = me - b.me;
		if (mem < 0)
			mem += mod;
		return mem;
	}
	modt operator *(modt b)
	{
		return 1LL * me * b.me % mod;
	}
	static modt pw(modt a, int b)
	{
		modt ans = 1;
		while (b)
		{
			if (b & 1)
				ans = ans * a;
			a = a * a;
			b >>= 1;
		}
		return ans;
	}
	static modt inv(modt a)
	{
		return pw(a, mod - 2);
	}
	modt operator /(modt b)
	{
		return *this * inv(b);
	}
};

vector<vector<modt>> diag(vector<vector<modt>> matr)
{
	if (matr.size() == 0 || matr[0].size() == 0)
		return matr;
	int a = matr.size();
	int b = matr[0].size();
	int ind = -1;
	for (int i = 0; i < a; ++i)
	{
		if (matr[i][0].me != 0)
		{
			ind = i;
			break;
		}
	}
	if (ind == -1)
	{
		auto matr1 = matr;
		for (auto& x : matr1)
			x.erase(x.begin());
		auto mem = diag(matr1);
		for (auto& x : mem)
			x.insert(x.begin(), 0);
		return mem;
	}
	swap(matr[0], matr[ind]);
	modt mult = modt(1) / matr[0][0];
	for (int i = 0; i < b; ++i)
		matr[0][i] = matr[0][i] * mult;
	for (int i = 1; i < a; ++i)
	{
		if (matr[i][0].me == 0)
			continue;
		modt lol = matr[i][0] / matr[0][0];
		for (int j = 0; j < b; ++j)
			matr[i][j] = matr[i][j] - matr[0][j] * lol;
	}
	auto mem = matr;
	mem.erase(mem.begin());
	for (auto& x : mem)
		x.erase(x.begin());
	mem = diag(mem);
	for (auto& x : mem)
		x.insert(x.begin(), 0);
	mem.insert(mem.begin(), matr[0]);
	vector<int> le(b, -1);
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			if (mem[i][j].me)
			{
				if (le[j] == -1)
					le[j] = i;
				break;
			}
		}
	}
	for (int i = 1; i < b; ++i)
	{
		int kek = le[i];
		if (kek == -1)
			continue;
		modt mult = mem[0][i] / mem[kek][i];
		for (int j = 0; j < b; ++j)
			mem[0][j] = mem[0][j] - mem[kek][j] * mult;

	}
	return mem;
}

int main()
{
	int m, d;
	cin >> m >> d;
	vector<vector<vector<int>>> st;
	for (int i = 0; i < m; ++i)
	{
		int k;
		cin >> k;
		vector<vector<modt>> matr(k, vector<modt>(d));
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < d; ++j)
			{
				int x;
				cin >> x;
				if (x < 0)
					x += mod;
				matr[i][j] = x;
			}
		matr = diag(matr);
		vector<vector<int>> m1(matr.size(), vector<int>(d));
		for (int i = 0; i < matr.size(); ++i)
		{
			int cnt = 0;
			for (int j = 0; j < d; ++j)
				cnt += matr[i][j].me != 0;
			if (cnt == 0)
			{
				m1.pop_back();
				continue;
			}
			for (int j = 0; j < d; ++j)
			{
				m1[i][j] = matr[i][j].me;
			}
		}
		/*
		for (int i = 0; i < m1.size(); ++i)
			for (int j = 0; j < m1[i].size(); ++j)
				cerr << m1[i][j] << " \n"[j + 1 == m1[i].size()];
		cerr << '\n';
		cerr << "kek" << '\n';
		*/
		st.push_back(m1);
	}
	vector<int> ord(m);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int a, int b)
			{
			return st[a] < st[b];
			});
	vector<vector<int>> comp;
	vector<int> cur;
	for (int x : ord)
	{
		if (cur.size() && st[cur.back()] != st[x])
			comp.push_back(cur), cur.clear();
		cur.push_back(x);
	}
	comp.push_back(cur);
	int t = 0;
	vector<int> arr(comp.size(), -1);
	vector<int> cmp(m);
	for (int i = 0; i < comp.size(); ++i)
		for (int j : comp[i])
			cmp[j] = i;
	for (int i = 0; i < m; ++i)
	{
		if (arr[cmp[i]] == -1)
			arr[cmp[i]] = t++;
		cout << arr[cmp[i]] + 1 << ' ';
	}
	cout << '\n';
}