h, w = map(int, input().split())
a = []
b = []
c = []
a.append('#' * (w+1))
for i in range(h):
    a.append('#' + input())
h += 1
w += 1
for i in range(h):
    b.append([0] * w)
    c.append([0] * w)
for i in range(1, h):
    for j in range(1, w):
        b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1]
        c[i][j] = c[i-1][j] + c[i][j-1] - c[i-1][j-1]
        if a[i][j]+a[i][j-1] == '..':
            b[i][j] += 1
        if a[i][j]+a[i-1][j] == '..':
            c[i][j] += 1

q = int(input())
for i in range(q):
    r1, c1, r2, c2 = map(int, input().split())
    ans = b[r2][c2] - b[r1-1][c2] - b[r2][c1] + b[r1-1][c1]
    ans += c[r2][c2] - c[r1][c2] - c[r2][c1-1] + c[r1][c1-1]
    print(ans)