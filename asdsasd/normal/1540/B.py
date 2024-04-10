import sys
input = sys.stdin.readline
from collections import deque
MOD = 10 ** 9 + 7
N = 1000
fact = [0 for _ in range(N)]
invfact = [0 for _ in range(N)]
fact[0] = 1
for i in range(1, N):
    fact[i] = fact[i - 1] * i % MOD

invfact[N - 1] = pow(fact[N - 1], MOD - 2, MOD)

for i in range(N - 2, -1, -1):
    invfact[i] = invfact[i + 1] * (i + 1) % MOD

def nCk(n, k):
    if k < 0 or n < k:
        return 0
    else:
        return (fact[n] * invfact[k] % MOD) * invfact[n - k] % MOD

def nHk(n, k):
    return nCk(n + k - 1, k)

def main():
    n = int(input())
    edges = [[] for _ in range(n)]
    for _ in range(n - 1):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        edges[x].append(y)
        edges[y].append(x)
        
    def cnt(i, j):
        bef = [-1] * n
        used = [False] * n
        stack = [i]
        while stack:
            pos = stack.pop()
            if pos == j:
                break
            for npos in edges[pos]:
                if used[npos]:
                    continue
                used[npos] = True
                bef[npos] = pos
                stack.append(npos)
        c = 0
        queue = deque()
        queue.append((j, 0))
        pos = j
        used = [False] * n
        used[pos] = True
        while pos != i:
            pos = bef[pos]
            c += 1
            queue.append((pos, c))
            used[pos] = True
        cnts = [1] * (c + 1)
        C = c
        while queue:
            pos, c = queue.popleft()
            for npos in edges[pos]:
                if used[npos]: continue
                used[npos] = True
                cnts[c] += 1
                queue.append((npos, c))
        ret = 0

        tot = 0
        times = 1
        inv = pow(pow(2, C - 1, MOD), MOD - 2, MOD)
        for i, c in enumerate(cnts[:-1]):
            ret += c * times
            ret %= MOD
            times -= nCk(C - 1, i) * inv
            times %= MOD
        
        return ret 
        
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
        
            ans += cnt(i, j)
            ans %= MOD
    ans *= pow(n, MOD - 2, MOD)
    print(ans % MOD)
    
        

for _ in range(1):
    main()