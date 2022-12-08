n = input()
m = 2 * n + 1
u = [[] for i in range(m)]
v = [0] * m
s = [0] * m
d = 10 ** 9 + 7
y = 1
for j in range(n):
    a, b = map(int, raw_input().split())
    v[a] = b
    if a != b:
        s[b] += 1
        u[b].append(a)
for b in range(m):
    if not v[b]:
        x = 0
        p = [b]
        while p:
            x += 1
            a = p.pop()
            s[a] = -1
            p += u[a]
        y = (x * y) % d
for a in range(m):
    if s[a] == 0:
        b = v[a]
        while s[b] == 1:
            s[b] = -1
            b = v[b]
        s[b] -= 1
for a in range(m):
    if s[a] == 1:
        y = (2 * y) % d
        while s[a]:
            s[a] = 0
            a = v[a]
print(y)