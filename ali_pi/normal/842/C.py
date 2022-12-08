from sys import stdin
from fractions import gcd

n = int(stdin.readline().strip())
v = map(int, stdin.readline().strip().split())

adj = [[] for _ in xrange(n)]
for _ in xrange(n-1):
    x, y = map(int, stdin.readline().strip().split())
    adj[x-1].append(y-1)
    adj[y-1].append(x-1)

root_divisors = []
cnt = [0]*200001
d = 1
while d*d <= v[0]:
    if v[0] % d == 0:
        root_divisors.append(d)
        cnt[d] += 1
        if v[0]/d != d:
            root_divisors.append(v[0]/d)
            cnt[v[0]/d] += 1
    d += 1    
s = [0]
visited = [False]*n
visited[0] = True
level = [1]*n
res1 = [0]*n
res2 = [0]*n
res1[0] = v[0]
d = 1
while s:
    x = s[-1]
    any_more = False
    while adj[x]:
        y = adj[x].pop()
        if not visited[y]:
            visited[y] = True
            any_more = True
            s.append(y)
            level[y] = level[x]+1
            res2[y] = gcd(res2[x], v[y])
            for d in root_divisors:
                if v[y] % d == 0:
                    cnt[d] += 1
                if cnt[d] == level[y] or cnt[d] == level[y]-1:
                    res1[y] = max(res1[y], res2[y], d)
            break
    if not any_more:
        s.pop()
        for d in root_divisors:
            if v[x] % d == 0:
                cnt[d] -= 1
print ' '.join(map(str, res1))