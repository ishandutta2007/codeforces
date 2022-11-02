n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(input())
b = []
c = []
for i in range(n):
    for j in range(m):
        if a[i][j] == '*':
            b.append(i)
            c.append(j)
b = sorted(b)
c = sorted(c)
if b[0] == b[1]:
    print(b[-1] + 1, end = ' ')
else:
    print(b[0] + 1, end = ' ')

if c[0] == c[1]:
    print(c[-1] + 1)
else:
    print(c[0] + 1)