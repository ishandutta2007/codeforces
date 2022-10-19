#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

int main() {
#ifdef Asuka
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		set<int> A, B;

		rep(i, 1, n) {
			int x;
			scanf("%d", &x);
			if (x == 0) A.insert(i);
			else B.insert(i);
		} 

		int ans = 0;

		while (!A.empty() && !B.empty() && *A.rbegin() > *B.begin()) {
			B.erase(B.begin());
			B.insert(*A.rbegin());
			A.erase(--A.end());
			ans++;
		}

		printf("%d\n", ans);
	}
	
	return 0;
}