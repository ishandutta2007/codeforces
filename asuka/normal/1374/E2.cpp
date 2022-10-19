#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, m, k, need, ssum;
vector<pii> II, OI, IO, O;
multiset<pii> S, OO;
void adjust() {
	auto pfront = [&]() {
		ssum += OO.begin() -> fi;
		S.insert(*OO.begin());
		OO.erase(OO.begin());
	};
	auto pback = [&]() {
		OO.insert(*S.rbegin());
		ssum -= S.rbegin() -> fi;
		S.erase(S.find(*S.rbegin()));
	};
	while(SZ(S) < need && SZ(OO) > 0) pfront();
	while(SZ(S) > need && SZ(S) > 0) pback();
	while(SZ(S) > 0 && SZ(OO) > 0) {
		if(OO.begin() -> fi < S.rbegin() -> fi) {
			pfront();
			pback();
		} else break;
	}
	while(SZ(S) < need && SZ(OO) > 0) pfront();
	while(SZ(S) > need && SZ(S) > 0) pback();
}
void fuck(int lzjak) {
	int Isum = 0, sum = 0;
	ssum = 0;
	S.clear();
	OO.clear();
	rep(i, 1, min(k, SZ(IO))) sum += IO[i - 1].fi;
	rep(i, k + 1, SZ(IO)) OO.insert(IO[i - 1]);
	rep(i, 1, min(k, SZ(OI))) sum += OI[i - 1].fi;
	rep(i, k + 1, SZ(OI)) OO.insert(OI[i - 1]);
	for(auto x : O) OO.insert(x);
	rep(i, 1, SZ(II)) OO.insert(II[i - 1]);
	rep(i, 0, min(m, SZ(II))) { // II choose i
		need = m - i - min(k - i, SZ(IO)) - min(k - i, SZ(OI));
		adjust();
		if(i == lzjak) {
			rep(j, 1, i) printf("%d ", II[j - 1].se);
			rep(j, 1, min(k - i, SZ(IO))) printf("%d ", IO[j - 1].se);
			rep(j, 1, min(k - i, SZ(OI))) printf("%d ", OI[j - 1].se);
			for(auto lzjakioi : S) printf("%d ", lzjakioi.se);
			printf("\n");
			return;
		}
		if(i < SZ(II)) {
			Isum += II[i].fi;
			if(S.find(II[i]) != S.end()) S.erase(S.find(II[i]));
			else OO.erase(OO.find(II[i]));
		}
		if(0 < k - i && k - i <= SZ(IO)) sum -= IO[k - i - 1].fi, OO.insert(IO[k - i - 1]);
		if(0 < k - i && k - i <= SZ(OI)) sum -= OI[k - i - 1].fi, OO.insert(OI[k - i - 1]);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	int ans = 2e9 + 5, pos = -1;
	rep(i, 1, n) {
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if(a == 1 && b == 1) II.pb(mp(t, i));
		if(a == 1 && b == 0) IO.pb(mp(t, i));
		if(a == 0 && b == 1) OI.pb(mp(t, i));
		if(a == 0 && b == 0) OO.insert(mp(t, i)), O.pb(mp(t, i));
	}
	sort(all(II));
	sort(all(IO));
	sort(all(OI));
	int Isum = 0, sum = 0;
	rep(i, 1, min(k, SZ(IO))) sum += IO[i - 1].fi;
	rep(i, k + 1, SZ(IO)) OO.insert(IO[i - 1]);
	rep(i, 1, min(k, SZ(OI))) sum += OI[i - 1].fi;
	rep(i, k + 1, SZ(OI)) OO.insert(OI[i - 1]);
	rep(i, 1, SZ(II)) OO.insert(II[i - 1]);
	rep(i, 0, min(m, SZ(II))) { // II choose i
		need = m - i - min(k - i, SZ(IO)) - min(k - i, SZ(OI));
		adjust();
		// printf("I %d\n", i);
		// printf("(%d %d %d)\n", sum, Isum, ssum);
		// for(auto x : S) printf("%d ", x.se);
		// printf("\n");
		// printf("%d\n", i);
		if(i + SZ(IO) >= k && i + SZ(OI) >= k && SZ(S) == need) {
			if(sum + Isum + ssum < ans) {
				pos = i;
			}
			ans = min(ans, sum + Isum + ssum);
		}
		if(i < SZ(II)) {
			Isum += II[i].fi;
			if(S.find(II[i]) != S.end()) S.erase(S.find(II[i])), ssum -= II[i].fi;
			else OO.erase(OO.find(II[i]));
		}
		if(0 < k - i && k - i <= SZ(IO)) sum -= IO[k - i - 1].fi, OO.insert(IO[k - i - 1]);
		if(0 < k - i && k - i <= SZ(OI)) sum -= OI[k - i - 1].fi, OO.insert(OI[k - i - 1]);
	}
	// puts("OK");
	printf("%d\n", ans > 2e9 ? -1 : ans);
	if(ans <= 2e9) {
		fuck(pos);
	}
	return 0;
}
/*
10 10 2
1 1 1
2 1 1
1 1 0
1 1 0
2 1 0
2 1 0
3 1 0
4 1 0
5 1 0
6 1 1

*/