def get(x, p):
    v = x
    while p[v] != v:
        v = p[v]
    while x != v:
        x, p[x] = p[x], v
    return v
n, k = map(int, input().split())
p = [0] * n
sz = [1] * n
for i in range(n):
    p[i] = i
for i in range(n-1):
    x, y, z = map(int, input().split())
    x-=1
    y-=1
    if z == 0:
        x = get(x, p)
        y = get(y, p)
        sz[x] += sz[y]
        p[y] = x
mod = 10**9 + 7
ans = pow(n, k, mod) 

for i in range(n):
    if p[i] == i:
        ans = (ans - pow(sz[i], k, mod)) % mod
print(ans)