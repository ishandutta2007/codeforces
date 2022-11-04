#include <bits/stdc++.h>

#define copy(x, y) memcpy(x, y, sizeof y);
#define M 2000010

using namespace std;

int nxt[M][26], pre[M], h[M], v[M], C[M], r[M], n, q, B[M], s = 0, cnt = 0;

char ch[4000010];

int add(int x)
{
	h[cnt + 1] = h[s] + 1;
	v[++cnt] = 1;
	while(s != -1 && !nxt[s][x]) nxt[s][x] = cnt, s = pre[s];
	if(s == -1) return s = cnt;
	int sn = nxt[s][x];
	if(h[sn] == h[s] + 1) return pre[cnt] = sn, s = cnt;
	h[++cnt] = h[s] + 1;
	copy(nxt[cnt], nxt[sn]);
	pre[cnt] = pre[sn];
	pre[sn] = pre[cnt - 1] = cnt;
	while(s != -1 && nxt[s][x] == sn) nxt[s][x] = cnt, s = pre[s];
	return s = cnt - 1;
}

int main()
{
	scanf("%s", ch), n = strlen(ch), pre[0] = -1;
	for(int i = 0; i < n; i++) add(ch[i] - 'a');
	for(int i = 1; i <= cnt; i++) C[h[i]]++;
	for(int i = 1; i <= cnt; i++) C[i] += C[i - 1];
	for(int i = 1; i <= cnt; i++) r[C[h[i]]--] = i;
	for(int i = cnt; i >= 1; i--)
		v[pre[r[i]]] += v[r[i]];
	scanf("%d", &q);
	for(int T = 1; T <= q; T++)
	{
		scanf("%s", ch), n = strlen(ch);
		for(int i = 0; i < n; i++) ch[i] -= 'a', ch[i + n] = ch[i];
		int nw = 0, ans = 0, len = 0;
		for(int i = 0; i < n * 2; i++)
		{
			while(nw && !nxt[nw][ch[i]]) nw = pre[nw], len = h[nw];
			if(nxt[nw][ch[i]]) nw = nxt[nw][ch[i]], len++;
			if(len == n)
			{
				if(B[nw] == T) break;
				ans += v[nw], B[nw] = T;
				if(h[pre[nw]] + 1 == len) nw = pre[nw];
				len--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}