from collections import*
n, m, k = map(int, input().split())
b = [[int(v) for v in input().split()] for _ in range(n)]
if m < n:
    a = [[b[j][i] for j in range(n)] for i in range(m)]
    b = a
    m, n = n, m
cntrs = [Counter() for _ in range(n)]
d = (n + m-1) // 2
for i in range(1<<d):
    ones = bin(i).count('1')
    z = d - ones
    if ones >= n or z >= m: continue
    xor = b[0][0]
    x, y = 0, 0
    for j in range(d):
        if i&(1<<j):
            x += 1
        else:
            y += 1
        xor ^= b[x][y]
    cntrs[x][xor] += 1
sm = 0
sleft = n + m - 2 - d
for i in range(1<<sleft):
    ones = bin(i).count('1')
    z = sleft - ones
    if ones >= n or z >= m: continue
    xor = b[n-1][m-1]
    x, y = n-1, m-1
    for j in range(sleft):
        if i&(1<<j):
            x -= 1
        else:
            y -= 1
        xor ^= b[x][y]
    xor ^= b[x][y] ^ k
    sm += cntrs[x][xor]
print(sm)