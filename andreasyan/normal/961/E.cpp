#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
int a[N];
long long ans;
vector<int> q[N];

int t[4 * N];
void ubd(int tl, int tr, int x, int pos)
{
	if (tl == tr)
	{
		t[pos]++;
		return;
	}
	int m = ((tl + tr) >> 1);
	if (x <= m)
		ubd(tl, m, x, (pos << 1));
	else
		ubd(m + 1, tr, x, (pos << 1) + 1);
	t[pos] = t[(pos << 1)] + t[(pos << 1) + 1];
}
long long qry(int tl, int tr, int l, int r, int pos) { if (l > r) return NULL; if (tl == l && tr == r) return t[pos]; int tm = (tl + tr) >> 1; return qry(tl, tm, l, min(r, tm), pos + pos) + qry(tm + 1, tr, max(l, tm + 1), r, pos + pos + 1); }

int main()
{
	cin >> n;
	int mm = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		a[i] = min(a[i], n);
		if (a[i] >= i)
			mm++;
		q[min(n, a[i])].push_back(i);
	}
	for (int i = 1; i <= n; ++i)
	{
		ubd(0, n, a[i], 1);
		for (int j = 0; j<q[i].size(); ++j)
			ans += qry(0, n, q[i][j], n, 1);
	}
	cout << (ans - mm) / 2 << endl;
	return 0;
}