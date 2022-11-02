n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in range(n):
    if a[i] != a[0]:
        ans = max(ans, i)
    if a[i] != a[-1]:
        ans = max(ans, n-i-1)
print(ans)