n = int(input())
a = list(map(int, input().split()))
b = dict()
ans = 0
for i in range(n):
    x = 1
    for k in range(0, 31):
        if x > a[i]:
            ans += b.get(x-a[i], 0)
        x *= 2
    b[a[i]] = b.get(a[i], 0) + 1
print(ans)