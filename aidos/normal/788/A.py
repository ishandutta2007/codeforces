n = int(input())
a = list(map(int, input().split()))
b = []
for i in range(1, n):
    b.append(abs(a[i] - a[i-1]))
n = len(b)
for i in range(n):
    b[i] *= (-1) ** (i % 2)
ans = 0
mx = 0
mi = 0
s = 0
for i in range(n):
    s += b[i]
    ans = max(ans, max(abs(s-mx), abs(s-mi)))
    mx = max(s, mx)
    mi = min(s, mi)
print(ans)