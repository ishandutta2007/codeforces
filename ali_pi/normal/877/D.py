from sys import *
f = lambda: map(int,raw_input().split())
n, m, k = f()
t = [[1e9 * (q == '.') for q in stdin.readline()] for i in range(n)]
t.append([0] * m)
a, b, c, d = [q - 1 for q in f()]
u = [(a, b)]
t[a][b] = l = 0
def g(i, x, y):
    if i > k or t[x][y] < l: return 0
    if t[x][y] > l:
        t[x][y] = l
        v.append((x, y))
    return 1
while u and t[c][d] == 1e9:
    l += 1
    v = []
    for x, y in u:
        i = j = 1
        while g(i, x - i, y): i += 1
        while g(j, x + j, y): j += 1
        i = j = 1
        while g(i, x, y - i): i += 1
        while g(j, x, y + j): j += 1
    u = v
print(l if t[c][d] < 1e9 else -1)