n, h, m = map(int, input().split())
a = [h] * n
for i in range(m):
    l, r, x = map(int, input().split())
    for j in range(l-1, r):
        a[j]=min(a[j], x)
ans = sum([x * x for x in a])
print(ans)