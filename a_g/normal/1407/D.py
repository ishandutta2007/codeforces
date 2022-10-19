import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, = I()
h = I()
G = [[] for _ in range(n)]
dp = [n]*n

for j in (-1, 1):
    stk = []
    for i in range(n):
        x = True
        while len(stk) > 0 and j*(h[stk[-1]]-h[i]) >= 0:
            if h[stk[-1]] == h[i]:
                x = False
            G[stk.pop()].append(i)
        if x and len(stk) > 0:
            G[stk[-1]].append(i)
        stk.append(i)

dp[0] = 0
for i in range(n):
    for j in G[i]:
        dp[j] = min(dp[j], dp[i]+1)
print(dp[-1])