n = int(input())
a = list(map(int, input().split()))

mx = 0
ans = 0
for i in range(n):
    mx = max(mx, a[i])
    if mx == i + 1:
        ans += 1
print(ans)