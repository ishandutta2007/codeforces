n = int(input())
p = [0] * (n+1)
a = [0] * (n+1)
x = 1
for i in range(2, n+1):
    for j in range(i, n+1, i):
        if p[j] == 0:
            p[j] = i
for i in range(2, n + 1):
    if a[p[i]] == 0:
        a[p[i]] = x
        x += 1
    print(a[p[i]], end = ' ')