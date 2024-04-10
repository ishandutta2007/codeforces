#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, perm[105], nxt[105], pre[105];
int main()
{
	scanf("%d", &n);
	rep1(i, n) {
		printf("?"); rep1(j, n) printf(" %d", j == i ? 2 : 1); printf("\n"); fflush(stdout);
		int x;
		scanf("%d", &x);
		if(x != i) nxt[i] = x;
	}
	rep1(i, n) {
		printf("?"); rep1(j, n) printf(" %d", j == i ? 1 : 2); printf("\n"); fflush(stdout);
		int x;
		scanf("%d", &x);
		if(x != i) nxt[x] = i;
	}
	
	rep1(i, n) pre[nxt[i]] = i;
	rep1(i, n) if(pre[i] == 0) {
		rep1(j, n) {
			perm[i] = j; i = nxt[i];
		}
		break;
	}
	printf("! "); rep1(i, n) printf("%d ", perm[i]); fflush(stdout);
	return 0;
}