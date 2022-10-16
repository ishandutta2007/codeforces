/*

 y 
 y < i   y > i  


*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#define ll long long
#define inf 0x3f3f3f3f
#define int unsigned int
using namespace std;
namespace ywy {
	inline int get() {
	    int n = 0;
	    char c;
	    while ((c = getchar()) || 23333) {
	        if (c >= '0' && c <= '9')
	            break;
	        if (c == '-')
	            goto s;
	    }
	    n = c - '0';
	    while ((c = getchar()) || 23333) {
	        if (c >= '0' && c <= '9')
	            n = n * 10 + c - '0';
	        else
	            return (n);
	    }
	s:
	    while ((c = getchar()) || 23333) {
	        if (c >= '0' && c <= '9')
	            n = n * 10 - c + '0';
	        else
	            return (n);
	    }
	}
	typedef struct _pt {
	    int x;
	    int y;
	    _pt() { x = y = 0; }
	    _pt(int i, int j) {
	        x = i;
	        y = j;
	    }
	    friend bool operator==(const _pt &a, const _pt &b) { return (a.x == b.x && a.y == b.y); }
	    friend bool operator<(const _pt &a, const _pt &b) {
	        if (a.x == b.x)
	            return (a.y < b.y);
	        return (a.x < b.x);
	    }
	} pt;
	map<pt, int> mp;
	vector<int> vec[400001];
	int id[300001];
	vector<int> blo[300001];
	unsigned char bv[300001];
	signed *cpre[300001], *csuf[300001];
	typedef struct _b {
	    int dest;
	    int nxt;
	} bian;
	bian memchi[1000001];
	int gn = 1, heads[300001], fa[300001], zx, tot, ch[300001][2];
	inline void add(int s, int t) {
	    memchi[gn].dest = t;
	    memchi[gn].nxt = heads[s];
	    heads[s] = gn;
	    gn++;
	}
	int deep[25][300001], size[300001];
	void afs(int pt, int baba) {
	    tot++;
	    for (register int i = heads[pt]; i; i = memchi[i].nxt) {
	        if (memchi[i].dest == baba || bv[memchi[i].dest])
	            continue;
	        afs(memchi[i].dest, pt);
	    }
	}
	void bfs(int pt, int baba) {
	    size[pt] = 1;
	    int mx = 0;
	    for (register int i = heads[pt]; i; i = memchi[i].nxt) {
	        if (memchi[i].dest == baba || bv[memchi[i].dest])
	            continue;
	        bfs(memchi[i].dest, pt);
	        size[pt] += size[memchi[i].dest];
	        mx = max(mx, size[memchi[i].dest]);
	    }
	    if (max(mx, tot - size[pt]) <= tot / 2)
	        zx = pt;
	}
	pt pts[400001];
	inline int cmp(const int &a, const int &b) { return (pts[a].y < pts[b].y); }
	int dst[25][300001];
	int dk;
	void cfs(int pt, int baba) {
	    for (register int i = (int)blo[pt].size() - 2; i >= 1; i--) {
	        if (dst[dk][blo[pt][i]] == 0x7f7f7f7f) {
	            dst[dk][blo[pt][i]] = dst[dk][blo[pt][i + 1]];
	            deep[dk][blo[pt][i]] = deep[dk][blo[pt][i + 1]] + 1;
	        }
	    }
	    for (register int i = 1; i < blo[pt].size(); i++) {
	        int me = blo[pt][i];
	        if (dst[dk][me] == 0x7f7f7f7f) {
	            dst[dk][me] = dst[dk][blo[pt][i - 1]];
	            deep[dk][me] = deep[dk][blo[pt][i - 1]] + 1;
	        }
	        for (register int j = 0; j <= 1; j++) {
	            if (!ch[me][j] || bv[id[ch[me][j]]] || id[ch[me][j]] == baba)
	                continue;
	            dst[dk][ch[me][j]] = dst[dk][me];
	            deep[dk][ch[me][j]] = deep[dk][me] + 1;
	        }
	    }
	    for (register int i = heads[pt]; i; i = memchi[i].nxt) {
	        if (bv[memchi[i].dest] || memchi[i].dest == baba)
	            continue;
	        cfs(memchi[i].dest, pt);
	    }
	}
	int rdeep[300001];
	void digui(int pt, int baba, int dp) {
	    dk = dp;
	    tot = 0;
	    afs(pt, 0);
	    bfs(pt, 0);
	    int me = zx;
	    fa[me] = baba;
	    for (register int i = 1; i < blo[me].size(); i++) dst[dp][blo[me][i]] = blo[me][i];
	    cfs(me, 0);
	    bv[me] = 1;
	    rdeep[me] = dp;
	    for (register int i = heads[me]; i; i = memchi[i].nxt) {
	        if (bv[memchi[i].dest])
	            continue;
	        digui(memchi[i].dest, me, dp + 1);
	    }
	}
	int fan[300001];
	void ywymain() {
	    int n = get();
	    for (register int i = 1; i <= n; i++) {
	        int x = get(), y = get();
	        pts[i].x = x;
	        pts[i].y = y;
	        mp[pts[i]] = i;
	        vec[x].push_back(i);
	    }
	    int gpt = 1;
	    for (register int i = 1; i <= 300000; i++) {
	        sort(vec[i].begin(), vec[i].end(), cmp);
	        int lsty = 13327734, lst = 0;
	        for (register int j = 0; j < vec[i].size(); j++) {
	            if (pts[vec[i][j]].y != lsty + 1)
	                lst = gpt, gpt++, blo[lst].push_back(0);
	            id[vec[i][j]] = lst;
	            blo[lst].push_back(vec[i][j]);
	            lsty = pts[vec[i][j]].y;
	        }
	    }
	    for (register int i = 1; i <= n; i++) {
	        ch[i][0] = mp[_pt(pts[i].x - 1, pts[i].y)];
	        ch[i][1] = mp[_pt(pts[i].x + 1, pts[i].y)];
	    }
	    for (register int i = 1; i < gpt; i++) {
	        cpre[i] = new signed[blo[i].size() + 1];
	        csuf[i] = new signed[blo[i].size() + 1];
	        for (register int j = 1; j < blo[i].size(); j++) {
	            fan[blo[i][j]] = j;
	            cpre[i][j] = inf;
	            csuf[i][j] = inf;
	            if (ch[blo[i][j]][0] && !bv[id[ch[blo[i][j]][0]]]) {
	                add(i, id[ch[blo[i][j]][0]]);
	                add(id[ch[blo[i][j]][0]], i);
	                bv[id[ch[blo[i][j]][0]]] = 1;
	            }
	        }
	        for (register int j = 1; j < blo[i].size(); j++) bv[id[ch[blo[i][j]][0]]] = 0;
	    }
	    memset(dst, 0x7f, sizeof(dst));
	    digui(1, 0, 0);
	    int q = get();
	    while (q) {
	        q--;
	        int op = get(), x = get(), y = get(), pos = mp[_pt(x, y)];
	        if (op == 1) {
	            int cur = id[pos];
	            while (cur) {
	                int me = dst[rdeep[cur]][pos];
	                for (register int i = fan[me]; i < blo[cur].size(); i += (i & -i)) {
	                    cpre[cur][i] = min(cpre[cur][i], (signed)deep[rdeep[cur]][pos] - (signed)fan[me]);
	                }
	                for (register int i = fan[me]; i > 0; i -= (i & -i)) {
	                    csuf[cur][i] = min(csuf[cur][i], (signed)deep[rdeep[cur]][pos] + (signed)fan[me]);
	                }
	                cur = fa[cur];
	            }
	        } else {
	            int minn = inf, cur = id[pos];
	            while (cur) {
	                int me = dst[rdeep[cur]][pos];
	                for (register int i = fan[me]; i > 0; i -= (i & -i)) {
	                    minn = min(minn, fan[me] + cpre[cur][i] + deep[rdeep[cur]][pos]);
	                }
	                for (register int i = fan[me]; i < blo[cur].size(); i += (i & -i)) {
	                    minn = min(minn, csuf[cur][i] - fan[me] + deep[rdeep[cur]][pos]);
	                }
	                cur = fa[cur];
	            }
	            if (minn > 10000000)
	                printf("-1\n");
	            else
	                printf("%d\n", minn);
	        }
	    }
	}
}
signed main() {
    ywy::ywymain();
    return (0);
}