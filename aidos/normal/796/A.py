n, m, k = map(int, input().split())
a = list(map(int, input().split()))
ans = n ** 2
for i in range(n):
    if a[i] > 0 and a[i] <= k:
        ans = min(ans, abs(m-1-i))
print(ans*10)