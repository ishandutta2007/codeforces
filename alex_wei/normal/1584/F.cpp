#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s)) 
const int N = 10;
const int S = 110;

int T, n, ap, aS, len[N], mp[1 << N];
int f[S][1 << N], buc[N][S], p[N][S][2];
pii tr[S][1 << N];
char s[N][S];
void print(int i, int S) {
	if(!i) return;
	print(tr[i][S].first, tr[i][S].second), putchar(s[0][i - 1]);
}
int main(){
	for(int i = 0; i < 26; i++) mp['a' + i] = i;
	for(int i = 0; i < 26; i++) mp['A' + i] = i + 26;
	cin >> T;
	while(T--) {
		cin >> n, mem(f, 0, S), mem(buc, 0, N), ap = aS = 0;
		for(int i = 0; i < n; i++) {
			cin >> s[i], len[i] = strlen(s[i]);
			for(int j = 0; j < len[i]; j++) {
				int id = mp[s[i][j]];
				p[i][id][buc[i][id]++] = j;
			}
		} for(int i = 0; i < len[0]; i++)
			for(int S = 0; S < 1 << n; S++) if(!i || f[i][S])
				for(int j = i + 1; j <= len[0]; j++) {
					int ok = 1, msk = 0, pr = i ? mp[s[0][i - 1]] : 0, su = mp[s[0][j - 1]];
					for(int q = 0; q < n && ok; q++) {
						int b = S >> q & 1;
						if(!buc[q][su] || i && buc[q][pr] <= b) {ok = 0; break;}
						if(!i) continue;
						int cp = p[q][pr][b], fd = -1;
						for(int k = 0; k < buc[q][su] && fd == -1; k++)
							if(p[q][su][k] > cp) fd = k;
						fd == -1 ? ok = 0 : msk |= fd << q;
					} int v = !i ? 1 : f[i][S] + 1;
					if(ok && f[j][msk] < v) {
						f[j][msk] = v, tr[j][msk] = {i, S};
						if(v > f[ap][aS]) ap = j, aS = msk;
					}
				} cout << f[ap][aS] << "\n", print(ap, aS), puts("");
	}
	return 0;
} //