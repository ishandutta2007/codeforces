    // 392699
     
    #include <bits/stdc++.h>
     
    using namespace std;
     
    template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
        for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
        for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
        a = f ? -a : a;
    }
    template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
    int fr() { int a; return fr(a), a; }
     
    const int N = 3e5;
     
    int fa[N + 10], cnt[N + 10];
    vector<int> e[N + 10], T[N + 10], ans[N + 10];
    map<int, int> V[N + 10];
    bool vis[N + 10];
     
    void adde(int x, int y) {
    	e[x].push_back(y);
    }
     
    void dfs(int u) {
    	vis[u] = 1;
    	for (auto v : e[u])
    		if (vis[v] == 0) dfs(v), fa[v] = u, T[u].push_back(v), T[v].push_back(u); //printf("%d %d\n", u, v);
    }
     
    struct OI {
        int RP, score;
    } CSPS2021, NOIP2021, FJOI2022;
     
    signed main() {
        CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
        int n = fr(), m = fr(), tot = 0;
        for (int i = 1, x, y; i <= m; i++) fr(x, y), adde(x, y), adde(y, x);
        dfs(1);
    	int q = fr();
    	for (int i = 1; i <= q; i++) {
    		int u = fr(), v = fr(), LCA = -1;
    		for (int j = 1; j <= n; j++) vis[j] = 0;
    		for (int j = u; j; j = fa[j]) vis[j] = 1;
    		for (int j = v; j; j = fa[j])
    			if (vis[j]) {
    				LCA = j;
    				break;
    			}
    //		printf("LCA = %d\n", LCA);
    		for (int j = u; j; j = fa[j]) {
    //			printf("%d ", j);
    			ans[i].push_back(j);
    			if (j == LCA) break;
    //			printf("(%d, %d)++\n", j, fa[j]);
    			V[j][fa[j]]++, V[fa[j]][j]++;
    		}
    		vector<int> tmp;
    		if (LCA != v)
    		for (int j = v; j; j = fa[j]) {
    //			printf("%d ", j);
    //			ans[i].push_back(j);
    			tmp.push_back(j);
    			V[j][fa[j]]++, V[fa[j]][j]++;
    //			printf("(%d, %d)++\n", j, fa[j]);
    			if (fa[j] == LCA) break;
    		}
    		reverse(tmp.begin(), tmp.end());
    		for (auto j : tmp) ans[i].push_back(j);
    //		puts("");
    	}
    	for (int i = 2; i <= n; i++)
    		if (V[i][fa[i]] & 1) tot++;
    	if (tot) {
    		puts("NO");
    		for (int i = 1; i <= n; i++)
    			for (auto v : T[i]) cnt[i] += (V[v][i] & 1);
    		tot = 0;
    		for (int i = 1; i <= n; i++)
    			if (cnt[i] & 1) tot++;
    		printf("%d\n", tot / 2); 
    	}
    	else {
    		puts("YES");
    		for (int i = 1; i <= q; i++) {
    			printf("%d\n", ans[i].size());
    			for (auto j : ans[i]) printf("%d ", j);
    			puts("");
    		}
    	}
        return 0;
    }