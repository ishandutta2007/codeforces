n, m = map(int, input().split())
a = []

b = []
for i in range(n):
    a.append(input())
    b.append([0] * m)
for i in range(1, n-1):
    for j in range(1, m-1):
        if a[i-1][j-1:j+2] == '###' and a[i][j-1] == '#' and a[i][j+1] == '#' and a[i+1][j-1:j+2] == '###':
            b[i-1][j-1] = 1
            b[i-1][j] = 1
            b[i-1][j+1] = 1
            b[i][j-1] = 1
            b[i][j+1] = 1
            b[i+1][j-1] = 1
            b[i+1][j] = 1
            b[i+1][j+1] = 1
ans = 0
for i in range(n):
    for j in range(m):
        if a[i][j] == '#' and b[i][j] == 0:
            ans = 1
if ans == 1:
    print('NO')
else:
    print('YES')