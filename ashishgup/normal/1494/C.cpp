#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m;
int a[N], b[N];

int getLess(vector<int> &va, int x)
{
	auto it = upper_bound(va.begin(), va.end(), x) - va.begin();
	return it;
}

int solvePositive()
{
	vector<int> va, vb;
	set<int> s;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] >= 1)
			va.push_back(a[i]);
	}
	for(int i = 1; i <= m; i++)
	{
		if(b[i] >= 1)
		{
			s.insert(b[i]);
			vb.push_back(b[i]);
		}
	}
	if(!vb.size() || !va.size())
		return 0;
	vector<int> pref(va.size(), 0);
	int asz = va.size(), bsz = vb.size();
 	for(int i = 0; i < asz; i++)
	{
		if(s.find(va[i]) != s.end())
		{
			if(i == 0)
				pref[i] = 1;
			else
				pref[i] = pref[i - 1] + 1;
		}
		else
		{
			if(i == 0)
				pref[i] = 0;
			else
				pref[i] = pref[i - 1];
		}
	}

	int ans = pref.back();

	for(auto &it:vb)
	{
		if(it < va[0])
			continue;
		int pos = it;
		int lo = pos, hi = pos + asz - 1;
		while(lo < hi)
		{
			int mid = (lo + hi + 1) / 2;
			int reqd = mid - pos + 1;
			int have = getLess(va, mid);
			if(have >= reqd)
				lo = mid;
			else
				hi = mid - 1;
		}
		int curAns = getLess(vb, lo) - getLess(vb, pos - 1);
		auto idx = upper_bound(va.begin(), va.end(), lo + 1) - va.begin();
		if(idx != asz)
			curAns += pref.back() - pref[idx - 1];
		ans = max(ans, curAns);
	}
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= m; i++)
			cin >> b[i];
		int ans = solvePositive();
		for(int i = 1; i <= n; i++)
			a[i] *= -1;
		for(int i = 1; i <= m; i++)
			b[i] *= -1;
		sort(a + 1, a + n + 1);
		sort(b + 1, b + m + 1);
		ans += solvePositive();
		cout << ans << endl;
	}
	return 0;
}