n = int(input())
a = []
b = []
for _ in range(n):
    x, y = map(int, input().split())
    if x < 0:
        a.append([-x, y])
    else:
        b.append([x, y])
a = sorted(a)
b = sorted(b)
k = min(len(a), len(b))
ss = 0
for i in range(k):
    ss += a[i][1] + b[i][1]
if len(a) > k:
    ss += a[k][1]
if len(b) > k:
    ss += b[k][1]
print(ss)