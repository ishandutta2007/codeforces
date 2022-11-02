n, l = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
d = []
for t in range(1, n):
    d.append((b[t] - b[t-1]) % l)
ok = "NO"
for i in range(n):
    c = []
    for j in range(1, n):
        c.append((a[(i+j) % n] - a[(i+j-1) % n]) % l)
    if c == d:
        ok = "YES"
print(ok)