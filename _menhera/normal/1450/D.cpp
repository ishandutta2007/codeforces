#include<bits/stdc++.h>
using namespace std;
int N;
const int MAXN = 524288;
pair<int, int> idx[2*MAXN];
pair<int, int> getv(int a, int b)
{
	a += MAXN; b += MAXN;
	pair<int, int> ans = {MAXN, -1};
	while(a<=b)
	{
		if(a%2 == 1) ans = min(ans, idx[a++]);
		if(b%2 == 0) ans = min(ans, idx[b--]);
		a /= 2; b /= 2;
	}
	return ans;
}
void setv(int a, pair<int, int> v)
{
	idx[a+=MAXN] = v;
	while((a=a/2)) idx[a] = min(idx[2*a], idx[2*a+1]);
}
int main()
{
	int T; scanf("%d", &T); while(T--)
	{
		int N; scanf("%d", &N);
		vector<int> arr;
		for(int i=0; i<N; ++i)
		{
			int t; scanf("%d", &t); setv(i, {t, i});
			arr.push_back(t);
		}

		auto cl = [&](int idx)
		{
			int lo = -1;
			int hi = idx; //[hi, idx] ok
			while(lo+1!=hi)
			{
				int mi = (lo+hi)/2;
				if(getv(mi, idx).second == idx) hi = mi;
				else lo = mi;
			}
			return hi;
		};
		auto cr = [&](int idx)
		{
			int lo = idx; //[idx, lo] ok
			int hi = N;
			while(lo+1!=hi)
			{
				int mi = (lo+hi)/2;
				if(getv(idx, mi).second == idx) lo = mi;
				else hi = mi;
			}
			return lo;
		};

		vector<vector<int> > lifes(N+1);
		string ans;
		// calculate lifetime
		for(int i=0; i<N; ++i)
		{
			int v = N-cr(i)+cl(i);
			lifes[v].push_back(i);
		}
		vector<bool> used(N+1);
		int maxv = 0, cnt = 0; bool burst = false;
		for(int i=1; i<=N; ++i)
		{
			for(auto x: lifes[i])
			{
				++cnt;
				int v = arr[x];
				maxv = max(v, maxv);
				if(used[v]) burst = true;
				else used[v] = true;
			}
			if(cnt == i && maxv == i && !burst) ans += '1';
			else ans += '0';
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}