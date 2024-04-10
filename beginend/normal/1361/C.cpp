#include<bits/stdc++.h>
using namespace std;

const int N = 1048580;

int n, bin[25], deg[N], f[N], a[N], b[N], last[N], cnt, sta[N], ans[N];
struct edge{int to, next, id, flag;}e[N];

int find(int x)
{
	return f[x] == x ? x : f[x] = find(f[x]);
}

bool check(int t)
{
	for (int i = 0; i < bin[t]; i++) deg[i] = 0, f[i] = i;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = a[i] & (bin[t] - 1), y = b[i] & (bin[t] - 1);
		if (!deg[x]) tot++;
		if (!deg[y] && x != y) tot++;
		deg[x]++;
		deg[y]++;
		if (find(x) != find(y)) tot--, f[find(x)] = find(y);
	}
	if (tot > 1) return 0;
	for (int i = 0; i < bin[t]; i++)
		if (deg[i] & 1) return 0;
	return 1;
}

    void work(int t)
    {
        int top = 0, s, tot = 0;
        for (int i = 0; i < bin[t]; i++) if (deg[i]) {s = i; break;}
        sta[++top] = s;
        while (top)
        {
            int x = sta[top];
            while (e[last[x]].flag) last[x] = e[last[x]].next;
            if (last[x])
            {
                sta[++top] = e[last[x]].to;
                f[top] = e[last[x]].id;
                e[last[x]].flag = e[last[x] ^ 1].flag = 1;
                last[x] = e[last[x]].next;
            }
            else
            {
                while (top && !last[sta[top]])
				{
					if (top > 1) ans[++tot] = f[top];
					top--;
				}
        	}
   	 	}
    	while (tot) printf("%d %d ", ans[tot], (ans[tot] & 1) ? ans[tot] + 1 : ans[tot] - 1), tot--;
	}

void pri(int t)
{
	printf("%d\n", t);
	cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		int x = a[i] & (bin[t] - 1), y = b[i] & (bin[t] - 1);
		e[++cnt].to = y; e[cnt].next = last[x]; e[cnt].id = i * 2 - 1; last[x] = cnt;
		e[++cnt].to = x; e[cnt].next = last[y]; e[cnt].id = i * 2; last[y] = cnt;
	}
	work(t);
}

int main()
{
	bin[0] = 1;
	for (int i = 1; i <= 20; i++) bin[i] = bin[i - 1] * 2;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
	for (int i = 20; i >= 0; i--)
		if (check(i))
		{
			pri(i);
			return 0;
		}
	return 0;
}