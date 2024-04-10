n = int(input())
a = input()
b = dict()
c = dict()
for i in a:
    b[i] = b.get(i, 0) + 1

r = 0
ans = n
for i in range(n):
    while len(c) < len(b) and r < n:
        c[a[r]] = c.get(a[r], 0) + 1
        r += 1
    if r == n and len(c) < len(b):
        break
    c[a[i]] = c.get(a[i], 0) - 1
    ans = min(ans, r-i)
    
    if c[a[i]] < 1:
        del c[a[i]]
print(ans)