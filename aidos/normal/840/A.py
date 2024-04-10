
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = []
for i in range(n):
    c.append([b[i], i])
c = sorted(c)
a = sorted(a)
p = [0] * n
for x in range(n):
    p[c[x][1]] = a[n-x-1]
for i in range(n):
    print(p[i], end = ' ')