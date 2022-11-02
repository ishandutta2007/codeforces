n, k, m = map(int, input().split())
s = input().split()
a = list(map(int, input().split()))
b = [0] * (n+1)
a = [0] + a
for i in range(n):
    b[i] = a[i]
M = dict()
for i in range(k):
    d = list(map(int, input().split()))
    x = a[d[1]]
    for j in d[1:]:
        x = min(x, a[j])
    for j in d[1:]:
        b[j] = x

for i in range(n):
    M[s[i]] = b[i+1]
t = input().split()
ans = 0
for i in range(m):
    ans += M[t[i]]
print(ans)