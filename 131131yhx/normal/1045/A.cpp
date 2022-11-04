#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

#define inf 1000000007
#define M 3000010

using namespace std;

set <int> res;

int n, m, S = 1, T = 2, L[55555], R[55555], O[55555], Num[55555], ndcnt, OP[55555], tmp[55555], is2[55555], lll = 0;

struct maxflow {
    int Head[55555], Next[M], Go[M], Val[M], high[55555], amount[55555], now[55555], pre[55555], flow[55555], n, m, k, cnt, _2;

inline void addedge(int x, int y, int z)
{
    Go[++cnt] = y;
    Val[cnt] = z;
    Next[cnt] = Head[x];
    Head[x] = cnt;
    Go[++cnt] = x;
    Val[cnt] = 0;
    Next[cnt] = Head[y];
    Head[y] = cnt;
}

    void DFS1(int x, int g, int f = 0) {
        if(x <= ::n + 2 && x >= 3) {
            if(res.count(x - 2)) {
                lll = x - 2;
                printf("%d %d\n", g, x - 2);
                res.erase(x - 2);
            }
            _2--;
            return;
        }
        for(int T = Head[x]; T; T = Next[T]) if(Go[T] != ::S && Go[T] != f) {
            int lst = _2;
            if(Val[T ^ 1]) {
                DFS1(Go[T], g, x);
                Val[T ^ 1] += lst - _2;
                Val[T] -= lst - _2;
                lst = _2;
                if(_2 == 0) return;
            }
        }
    }
    
int mxflow(int n, int m, int S, int TT)
{
    bool found = 0;
    int ans = 0;
    int i = S;
    amount[0] = n + m + 2;
    int c = inf;
    while(high[i] < n + m + 2)
    {
        found = 0;
        int T = now[i];
        if(!T) T = Head[i];
        flow[i] = c;
        for(; T; T = Next[T])
            if(high[Go[T]] == high[i] - 1 && Val[T])
            {
                found = 1;
                pre[Go[T]] = T ^ 1;
                now[i] = T;
                if(c > Val[T]) c = Val[T];
                i = Go[T];
                if(i == TT)
                {
                    ans += c;
                    while(i != S)
                    {
                        Val[pre[i]] += c;
                        Val[pre[i] ^ 1] -= c;
                        i = Go[pre[i]];
                    }
                    c = inf;
                }
                break;
            }
        if(!found)
        {
            int MIN = n + m + 2, v;
            for(int T = Head[i]; T; T = Next[T])
                if(Val[T] && high[Go[T]] < MIN)
                    MIN = high[Go[T]], v = T;
            amount[high[i]]--;
            if(amount[high[i]] == 0) break;
            high[i] = MIN + 1;
            amount[MIN + 1]++;
            now[i] = v;
            if(i != S)
            {
                i = Go[pre[i]];
                c = flow[i];
            }
        }
    }
    for(int T = Head[TT]; T; T = Next[T])
        if(Val[T]) res.insert(Go[T] - 2);
    return ans;
}
    void init(){
        cnt = 1;
    }
    void deal() {
        for(int T = Head[S]; T; T = Next[T]) if(OP[Go[T] - ::n - 2] == 2) is2[Go[T] - ::n - 2] = Val[T ^ 1];
    }
} FLOW;

void build(int x, int l, int r) {
    Num[x] = ++ndcnt;
    if(l == r) {
        FLOW.addedge(Num[x], 2 + l, 1);
        return;
    }
    build(x * 2, l, (l + r) / 2);
    build(x * 2 + 1, (l + r) / 2 + 1, r);
    FLOW.addedge(Num[x], Num[x * 2], inf);
    FLOW.addedge(Num[x], Num[x * 2 + 1], inf);
}

void apply(int x, int L, int R, int l, int r, int v) {
    int md = (L + R) / 2;
    if(l == L && R == r) {
        FLOW.addedge(v, Num[x], 1);
        return;
    }
    if(l <= md) apply(x * 2, L, md, l, min(md, r), v);
    if(r > md) apply(x * 2 + 1, md + 1, R, max(md + 1, l), r, v);
}

bool cmp(int x, int y) {
    return R[x] < R[y];
}

int main() {
    FLOW.init();
    scanf("%d%d", &m, &n); // m : weapons / n : spaceships
    ndcnt = 2 + n + m;
    for(int i = 1; i <= n; i++) FLOW.addedge(i + 2, T, 1);
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        int op;
        scanf("%d", &op);
        OP[i] = op;
        if(op == 0) {
            int k;
            scanf("%d", &k);
            FLOW.addedge(S, n + 2 + i, 1);
            while(k--) {
                int v;
                scanf("%d", &v);
                FLOW.addedge(n + 2 + i, v + 2, 1);
            }
        } else if(op == 1) {
            FLOW.addedge(S, n + 2 + i, 1);
            int l, r;
            scanf("%d%d", &l, &r);
            L[i] = l, R[i] = r;
            apply(1, 1, n, l, r, n + 2 + i);
        } else if(op == 2) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            L[i] = a, R[i] = b, O[i] = c;
            FLOW.addedge(S, n + 2 + i, 2);
            FLOW.addedge(n + 2 + i, 2 + a, 1);
            FLOW.addedge(n + 2 + i, 2 + b, 1);
            FLOW.addedge(n + 2 + i, 2 + c, 1);
        }
    }
    printf("%d\n", FLOW.mxflow(ndcnt + 5, 0, S, T));
    FLOW.deal();
    for(int i = 1; i <= m; i++) if(OP[i] == 2 && is2[i] == 2) {
        FLOW._2 = 2, FLOW.DFS1(i + ::n + 2, i);
        if(FLOW._2) {
            while(1);
        }
    }
    for(int i = 1; i <= m; i++) if(OP[i] == 2 && is2[i] == 1) {
        FLOW._2 = 1, FLOW.DFS1(i + ::n + 2, i);
        if(R[i] != lll && res.count(R[i])) {
            printf("%d %d\n", i, R[i]);
            res.erase(R[i]);
        } else if(L[i] != lll && res.count(L[i])) {
            printf("%d %d\n", i, L[i]);
            res.erase(L[i]);
        } else if(O[i] != lll && res.count(O[i])) {
            printf("%d %d\n", i, O[i]);
            res.erase(O[i]);
        }
    }
    for(int i = ::n + 3; i <= ::n + ::m + 2; i++) if(OP[i - ::n - 2] == 0) FLOW._2 = 1, FLOW.DFS1(i, i - ::n - 2);
    int t = 0;
    for(int i = ::n + 3; i <= ::n + ::m + 2; i++) if(OP[i - ::n - 2] == 1) tmp[++t] = i - ::n - 2;
    sort(tmp + 1, tmp + t + 1, cmp);
    for(int i = 1; i <= t; i++) {
        int x = tmp[i], l = L[x], r = R[x];
        set <int>::iterator it = res.lower_bound(l);
        if(it != res.end() && *it <= r) {
            printf("%d %d\n", x, *it);
            res.erase(it);
        }
    }
    return 0;
}