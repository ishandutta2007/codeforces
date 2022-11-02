n = int(input())
a = list(map(int, input().split()))
e = []
for i in range(n):
    e.append([])
for i in range(1, n):
    x, y = map(int, input().split())
    e[x-1].append([i, y])

b = [0] * n
c = [0] * n
d = [(10**18)] * n
l = 0
r = 1
cnt = 0
while l < r:
    v = b[l]
    if c[l] - a[v] > d[l]:
        l += 1
        continue
    cnt += 1
    for x in e[v]:
        c[r] = c[l] + x[1]
        d[r] = min(d[l], c[l])
        b[r] = x[0]
        r += 1
    l += 1
print(n-cnt)