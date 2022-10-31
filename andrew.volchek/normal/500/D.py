import sys
from collections import deque

cost = []

def readarray(): return [int(x) for x in raw_input().split(' ')]

n = int(raw_input())
graph = [[] for i in xrange(n)]

for i in xrange(n - 1):
    u, v, c = readarray()
    u, v = u - 1, v - 1
    cost.append(c)
    graph[u].append((v, i))
    graph[v].append((u, i))
    

order = []
used = [0] * n
q = deque()

used[0] = 1
q.append(0)

while len(q):
    v = q.popleft()
    
    
    order.append(v)
    
    for (to, e) in graph[v]:
        if used[to]:
            continue
        used[to] = 1
        q.append(to)
        
order.reverse()
        
sz = [0 for x in xrange(n)]

for v in order:
    sz[v] = 1
    for (to, e) in graph[v]:
        sz[v] += sz[to]


distanceSum = 0
edgeMult = [0] * n

for v in xrange(n):
    for (to, e) in graph[v]:
        x = min(sz[v], sz[to])
        edgeMult[e] = x
        distanceSum += cost[e] * x * (n - x)
        
distanceSum = distanceSum // 2

queryCnt = int(raw_input())

ans = []

for i in xrange(queryCnt):
    x, y = readarray()
    x -= 1
    
    distanceSum -= cost[x] * edgeMult[x] * (n - edgeMult[x])
    cost[x] = y
    distanceSum += cost[x] * edgeMult[x] * (n - edgeMult[x])
    
    ans.append('%.10lf' % (1.0 * distanceSum / n / (n - 1) * 6.0))

print('\n'.join(ans))