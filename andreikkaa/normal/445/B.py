from sys import setrecursionlimit
setrecursionlimit(10000)

n, m = list(map(int, input().split()))

a = [[False for j in range(n + 1)] for i in range(n + 1)]
b = [False for i in range(n + 1)]

for i in range(m):
    x, y = list(map(int, input().split()))  
    a[x][y] = True
    a[y][x] = True
  
def r(i):
    if b[i]:
        return 0
    b[i] = True
    s = 0
    for j in range(1, n + 1):
        if a[i][j]:
            s += r(j)
    return s + 1

o = 1
for i in range(1, n + 1):
    if not b[i]:
        o *= 2 ** (r(i) - 1)
print(o)