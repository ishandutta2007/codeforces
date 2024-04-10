// LUOGU_RID: 90637490
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
#define int ll
vector<int> ev[300010][2];
struct Matrix
{
	int a[2][2];
}M0, M1, I;
inline void Init()
{
	M0.a[0][0] = 3, M0.a[0][1] = 0, M0.a[1][0] = 1, M0.a[1][1] = 2;
	M1.a[0][0] = 1, M1.a[0][1] = 2, M1.a[1][0] = 1, M1.a[1][1] = 2;
	I.a[0][0] = 1, I.a[0][1] = 0, I.a[1][0] = 0, I.a[1][1] = 1;
}
Matrix operator * (Matrix &a, Matrix &b)
{
	Matrix ans;
	ans.a[0][0] = (a.a[0][0] * b.a[0][0] + a.a[0][1] * b.a[1][0]) % mod;
	ans.a[0][1] = (a.a[0][0] * b.a[0][1] + a.a[0][1] * b.a[1][1]) % mod;
	ans.a[1][0] = (a.a[1][0] * b.a[0][0] + a.a[1][1] * b.a[1][0]) % mod;
	ans.a[1][1] = (a.a[1][0] * b.a[0][1] + a.a[1][1] * b.a[1][1]) % mod;
	return ans;
}
struct SEG
{
	Matrix val[1200010];
	#define lc(u) (u << 1)
	#define rc(u) (u << 1 | 1)
	inline void Build(int u, int l, int r)
	{
		if(l == r)
		{
			val[u] = M0;
			return;
		}
		int mid = (l + r) >> 1;
		Build(lc(u), l, mid), Build(rc(u), mid + 1, r);
		pushup(u);
	}
	inline void pushup(int u)
	{
		val[u] = val[lc(u)] * val[rc(u)];
	}
	inline void Modify(int u, int l, int r, int pos, bool is1)
	{
		if(pos < l || r < pos)
			return;
		if(l == pos && r == pos)
		{
			val[u] = (is1 ? M1 : M0);
			return;
		}
		int mid = (l + r) >> 1;
		Modify(lc(u), l, mid, pos, is1), Modify(rc(u), mid + 1, r, pos, is1);
		pushup(u);
	}
	inline Matrix Query(int u, int l, int r, int L, int R)
	{
		if(r < L || R < l)
			return I;
		if(L <= l && r <= R)
			return val[u];
		int mid = (l + r) >> 1;
		Matrix lans = Query(lc(u), l, mid, L, R), rans = Query(rc(u), mid + 1, r, L, R);
		pushup(u);
		return lans * rans;
	}
}S;
signed main()
{
	int n, m = 0;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%lld %lld", &l, &r);
		ev[l][0].push_back(i);
		ev[r + 1][1].push_back(i);
		m = max(m, r + 1);
	}
	Init();
	S.Build(1, 1, n);
	bool m1 = false;
	int ans = 0;
	for(int i = 0; i <= m; i++)
	{
		for(auto x: ev[i][0])
			if(x == 1)
				m1 = true;
			else
				S.Modify(1, 1, n, x, true);
		for(auto x: ev[i][1])
			if(x == 1)
				m1 = false;
			else
				S.Modify(1, 1, n, x, false);
		Matrix res = S.Query(1, 1, n, 2, n);
		int tot = ((!m1) * res.a[0][1] + m1 * res.a[1][1]) % mod;
		ans = (ans + tot) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}