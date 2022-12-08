from collections import defaultdict as dd, deque

input=raw_input
range=xrange
n,m = map(int,input().split())
s = [ord(c)-ord('a') for c in input()]
E = dd(list)
P = dd(list)
C = [0]*n
for i in range(n):
    E[i] = []
for _ in range(m):
    a,b = map(int,input().split())
    E[a-1].append(b-1)
    P[b-1].append(a-1)
    C[a-1] += 1

leafs = [v for v in E if len(E[v])==0]

used = [0]*n
DP = [[0]*27 for _ in range(n)]

for i in range(n):
    DP[i][s[i]] += 1

Q = deque()
for leaf in leafs:
    Q.append(leaf)

while Q:
    node = Q.pop()
    V = []
    for i in range(27):
        mx = 0
        for ch in E[node]:
            mx = max(mx,DP[ch][i])
        DP[node][i] += mx
    if used[leaf]: continue
    for pa in P[node]:
        C[pa] -= 1
        if C[pa] == 0:
            Q.append(pa)

if any(C):
    print(-1)
else:
    print(max(max(dp) for dp in DP))