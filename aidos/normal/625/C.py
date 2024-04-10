n, k = map(int, input().split())
a = []

for i in range(n):
    a.append([0]*n)

st = 1
for i in range(k-1):
    for j in range(n):
        a[j][i] = st
        st += 1
for i in range(n):
    for j in range(k-1, n):
        a[i][j] = st
        st += 1
ans = 0
for i in range(n):
    ans += a[i][k-1]
print(ans)
for i in range(n):
    for j in range(n):
        if j == n-1:
            print(a[i][j], end = '\n')
        else:
            print(a[i][j], end = ' ')