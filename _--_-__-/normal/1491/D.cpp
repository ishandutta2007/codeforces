#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int highbit(int x)
{
	return 1 << (31 - __builtin_clz(x));
}
int lowbit(int x)
{
	return x & -x;
}
bool check(int s, int t)
{
	if(s > t) return false;
	else if(s == t) return true;
	else if(s == 0) return false;
	
	int hs = highbit(s), ht = highbit(t);
	if(hs == ht) return check(s ^ hs, t ^ ht);
	else {
		while(t > 0) {
			if(lowbit(s) == 0 || lowbit(s) > lowbit(t)) return false;
			s ^= lowbit(s); t ^= lowbit(t);
		}
		return true;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf(check(u, v) ? "YES\n" : "NO\n");
	}
	return 0;
}