#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, q;
string S[1000005];
int dat[1000005];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	rep(i, n) cin >> S[i];
	
	rep1(i, n - 1) rep1(j, m - 1) dat[j] += S[i - 1][j] == 'X' && S[i][j - 1] == 'X';
	rep1(i, m - 1) dat[i] += dat[i - 1];
	
	cin >> q;
	rep(i, q) {
		int l, r;
		cin >> l >> r;
		if(dat[l - 1] == dat[r - 1]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}