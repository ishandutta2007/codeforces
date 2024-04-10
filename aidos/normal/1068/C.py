n, m = map(int, input().split())
a = []
for i in range(n):
    a.append([[i * n, i * n]])

for i in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    if x > y:
        x, y = y, x
    a[x].append([x*n, x * n + y])
    a[y].append([y*n, x * n + y])
for i in range(n):
    print(len(a[i]))
    for j in a[i]:
        print(j[0]+1, j[1] + 1)