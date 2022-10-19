#include<bits/stdc++.h>
#define ll long long
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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int t;
char s[200015];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	for (scanf("%d", &t); t; t--) {
		static int cnt[26];
		rep(i, 0, 25) cnt[i] = 0;
		scanf("%s", s + 1);
		int n = strlen(s + 1), i = 1;
		rep(j, 1, n) cnt[s[j] - 'a']++;
		while (1) {
			if (cnt[s[i] - 'a'] > 1) {
				cnt[s[i] - 'a']--;
				i++;
			} else {
				break;
			}
		}
		rep(j, i, n) printf("%c", s[j]);
		printf("\n");
	}

	return 0;
}