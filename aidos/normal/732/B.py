n, k = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
for i in range(1, n):
    x = max(0, k - a[i] - a[i-1])
    ans += x
    a[i] += x
print(ans)
for i in a:
    print(i, end = ' ')