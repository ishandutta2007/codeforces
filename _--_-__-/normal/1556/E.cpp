#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

struct segt
{
	LL tre[262144];
	void modify(int id, LL dat)
	{
		id |= 131072;
		tre[id] = dat;
		for(id >>= 1; id >= 1; id >>= 1) tre[id] = max(tre[id << 1], tre[id << 1 | 1]);
	}
	LL query(int l, int r)
	{
		l |= 131072; r |= 131072;
		LL ret = -INF;
		while(l < r) {
			if(l & 1) ret = max(ret, tre[l]);
			if(!(r & 1)) ret = max(ret, tre[r]);
			l = (l + 1) >> 1; r = (r - 1) >> 1;
		}
		if(l == r) ret = max(ret, tre[l]);
		return ret;
	}
}t, t1;

int n, q, a[100005], b[100005];
LL S[100005];

int main()
{
	scanf("%d%d", &n, &q);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) scanf("%d", &b[i]);
	rep(i, n) a[i] -= b[i];
	rep(i, n) S[i + 1] = S[i] + a[i];
	rep(i, n + 1) t.modify(i, S[i]);
	rep(i, n + 1) t1.modify(i, -S[i]);
	
	rep(i, q) {
		int l, r;
		scanf("%d%d", &l, &r); l --;
		if(S[l] == S[r] && t.query(l, r) == S[r]) printf("%lld\n", S[l] + t1.query(l, r)); 
		else printf("-1\n");
	}
	return 0;
}