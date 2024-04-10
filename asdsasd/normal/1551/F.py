import sys
input = sys.stdin.readline
from collections import defaultdict as dd

MOD = 10 ** 9 + 7

def main():
    input()
    n, k = map(int, input().split())
    edges = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        edges[u].append(v)
        edges[v].append(u)
    if k == 2:
        print(n * (n - 1) // 2)
        return
    
    global ans
    ans = 0
    def dfs(pos, bpos):
        ret = dd(int)
        ret[0] = 1
        if bpos == -1:
            lst = dd(list)
        for npos in edges[pos]:
            if npos == bpos:
                continue
            x = dfs(npos, pos)
            for k2, v in x.items():
                k2 += 1
                ret[k2] += v
                if bpos == -1:
                    lst[k2].append(v)
        if bpos == -1:
            return lst
        else:
            return ret
    for i in range(n):
        lst = dfs(i, -1)
        for k2, v in lst.items():
            if len(v) < k:
                continue
            dp = [0] * (k + 1)
            dp[0] = 1
            for i in v:
                for j in range(k, 0, -1):
                    dp[j] += dp[j - 1] * i
                    dp[j] %= MOD
            ans += dp[k]
            ans %= MOD
    print(ans % MOD)
    
for _ in range(int(input())):
    main()