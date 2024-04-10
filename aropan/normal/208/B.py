n = input()
a = raw_input().split()
d = list([0] * n for i in range(n))
for i in range(n):
    for j in range(n):
        d[i][j] = a[i][0] == a[j][0] or a[i][1] == a[j][1]

f = list(set() for i in range(n))
if (n < 4):
    print "YES" if all(list(d[x][n - 1] for x in range(n))) else "NO"
    exit(0)
f[n - 4].add(((n - 1) * n + n - 2) * n + n - 3)
for i in reversed(range(n - 3)):
    for j in f[i]:
        a = j % n
        b = j / n % n
        c = j / n / n % n 
        if d[i][c]:
            f[i - 1].add((b * n + a) * n + c)
        if d[b][c]:
            f[i - 1].add((c * n + a) * n + i)
print "YES" if any(d[i / n % n][i / n / n] and d[i / n / n][i % n] for i in f[-1]) else "NO"