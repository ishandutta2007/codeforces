#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 1 ; i <= (n) ; i++)
#define per(i, n) for (int i = (n) ; i >= 1 ; i--)
#define repi(n) for (int i = 1; i <= (n) ; i++)
#define mabs(n) ((n) > 0 ? (n) : (-n))
#define print(V) for (auto v: V) printf("%d ",v)
using namespace std;
typedef long long LL ;
const int maxn = 2e5 + 5;
const int mod = 998244353;

int n, m, Mi; LL a[maxn], f[maxn];
bool judge(int x)
{
	//Mi + 1 Left
	f[Mi + 1] = a[Mi + 1];
	f[Mi + 2] = a[Mi + 1];
	if (f[Mi + 1] >= a[Mi + 2] - x - 1) f[Mi + 2] = a[Mi + 2];
	if (f[Mi + 1] >= a[Mi + 2] - 1) f[Mi + 2] = a[Mi + 2] + x;
	for (int i = Mi + 3 ; i <= Mi + n ; i++)
	{
		f[i] = f[i - 1];
		if (f[i - 1] >= a[i] - 1) f[i] = max(f[i], a[i] + x);
		if (f[i - 1] >= a[i] - x - 1) f[i] = max(f[i], a[i]);
		if (f[i - 2] >= a[i] - x - 1) f[i] = max(f[i], a[i - 1] + x);
	}
	if (f[Mi + n] >= a[Mi + 1] + m - x - 1) return true;
	
	//Mi + 1 Right Mi + 2 Left
	f[Mi + 1] = a[Mi + 1] + x;
	f[Mi + 2] = a[Mi + 1] + x;
	if (f[Mi + 1] >= a[Mi + 2] - x - 1) f[Mi + 2] = max(f[Mi + 2], a[Mi + 2]);
	for (int i = Mi + 3 ; i <= Mi + n ; i++)
	{
		f[i] = f[i - 1];
		if (f[i - 1] >= a[i] - 1) f[i] = max(f[i], a[i] + x);
		if (f[i - 1] >= a[i] - x - 1) f[i] = max(f[i], a[i]);
		if (f[i - 2] >= a[i] - x - 1) f[i] = max(f[i], a[i - 1] + x);
	}
	if (f[Mi + n] >= a[Mi + 2] + m - x - 1) return true;
	return false;
}
int main()
{
	#ifdef FILE_TESTn
		freopen("partymaker.in", "r", stdin);
	#endif
	
	scanf("%d %d", &m, &n);
	repi(n) scanf("%lld", &a[i]);
	if (n == 1) {printf("%d\n", m - 1); return 0;}
	sort(a + 1, a + n + 1);
	repi(n) a[i + n] = a[i] + m;
	
	LL M = 0;
	repi(n) M = max(M, a[i + 1] - a[i]);
	repi(n) M == a[i + 1] - a[i]? Mi = i : 0;
	int lb = -1, rb = M;
	while (rb - lb > 1)
	{
		int mid = lb + rb >> 1;
		judge(mid) ? rb = mid : lb = mid;
	}
	printf("%d", rb);
	return 0;
}