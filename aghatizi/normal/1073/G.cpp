#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 4e5 + 20;

string s;

int n , gap , sa[maxn], pos[maxn], tmp[maxn], lcp[maxn] , Mn[maxn * 4];

inline bool sufCmp(int i, int j)
{
	if (pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap;
	j += gap;
	return (i < n && j < n) ? pos[i] < pos[j] : i > j;
}

inline void buildSA()
{
	for(int i = 0; i < n; i++)
		sa[i] = i, pos[i] = s[i];

	for (gap = 1;; gap *= 2)
	{
		sort(sa, sa + n, sufCmp);
		for(int i = 0; i < n - 1; i++)
			tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);

		for(int i = 0; i < n; i++)
			pos[sa[i]] = tmp[i];

		if (tmp[n - 1] == n - 1)
			break;
	}
}

inline void buildLCP()
{
	for(int i = 0, k = 0; i < n; i++)
		if (pos[i] != n - 1)
		{
			for (int j = sa[pos[i] + 1]; k < n && s[i + k] == s[j + k];)
				k++;

			lcp[pos[i]] = k;
			if(k)
				k--;
		}
}

void buildSeg(int s = 0 , int e = n - 1 , int v = 1)
{
	if(e - s < 2)
	{
		Mn[v] = lcp[s];
		return;
	}

	int m = (s + e) / 2;

	buildSeg(s , m , 2 * v);
	buildSeg(m , e , 2 * v + 1);

	Mn[v] = min(Mn[2 * v] , Mn[2 * v + 1]);
}

int GetLcp(int l , int r , int s = 0 , int e = n - 1 , int v = 1)
{
	if(l == r)
		return n - sa[l];

	if(l <= s && e <= r)
		return Mn[v];
	if(r <= s || e <= l)
		return maxn;

	int m = (s + e) / 2;

	return min(GetLcp(l , r , s , m , 2 * v) , GetLcp(l , r , m , e , 2 * v + 1));
}

int L[maxn] , R[maxn];

ll get(vector<int> x)
{
	for(auto &y : x)
		y = pos[y];

	sort(x.begin() , x.end());

	int m = x.size();
	m--;

	for(int i = 0; i < m; i++)
		tmp[i] = GetLcp(x[i] , x[i + 1]);

	stack<int> st;
	for(int i = 0; i < m; i++)
	{
		while(!st.empty() && tmp[st.top()] >= tmp[i])
			st.pop();

		if(st.empty())
			L[i] = -1;
		else
			L[i] = st.top();

		st.push(i);
	}

	while(!st.empty())
		st.pop();

	for(int i = m - 1; i >= 0; i--)
	{
		while(!st.empty() && tmp[st.top()] > tmp[i])
			st.pop();

		if(st.empty())
			R[i] = m;
		else
			R[i] = st.top();

		st.push(i);
	}

	ll res = 0;
	for(int i = 0; i < m; i++)
		res += 1LL * (R[i] - i) * (i - L[i]) * tmp[i];

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> n >> q >> s;

	buildSA();
	buildLCP();
	buildSeg();

	while(q--)
	{
		int k , l;

		cin >> k >> l;
		vector<int> A , B , C;
		while(k--)
		{
			int x;
			cin >> x;

			A.pb(x - 1);
			C.pb(x - 1);
		}

		while(l--)
		{
			int x;
			cin >> x;

			B.pb(x - 1);
			C.pb(x - 1);
		}

		cout << get(C) - get(B) - get(A) << endl;
	}
}