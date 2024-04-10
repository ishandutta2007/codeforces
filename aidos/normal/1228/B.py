n, m =map(int, input().split())
r = list(map(int, input().split()))
c = list(map(int, input().split()))
a = [[-1]*m for _ in range(n)]
ans = 1
mod = 10 ** 9 + 7
for i in range(n):
    j = 0
    while j < r[i]:
        a[i][j] = 1
        j += 1
    if j < m:
        a[i][j] = 0
for j in range(m):
    i = 0
    while i < c[j]:
        if a[i][j] != -1 and a[i][j] != 1:
            ans = 0
        a[i][j] = 1
        i += 1
    if i < n:
        if a[i][j] != -1 and a[i][j] != 0:
            ans = 0
        a[i][j] = 0
for i in range(n):
    for j in range(m):
        if a[i][j] == -1:
            ans = (ans * 2) % mod

print(ans)