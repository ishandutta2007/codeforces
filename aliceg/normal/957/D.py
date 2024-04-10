n = int(input())
m = list(map(int, input().split()))
a = [0] * n
k = 0
for i in range(n):
    k = max(k, m[i] + 1)
    a[i] = k
for i in range(n - 1, 0, -1):
    a[i - 1] = max(a[i] - 1, a[i - 1])
ans = 0
for i in range(n):
    ans += a[i] - m[i] - 1
print(ans)