n, k = map(int, input().split())
a = list(map(int, input().split()))
sum = 0
ans = -(10**11)
for i in range(n):
    sum = 0
    for j in range(i, n):
        sum += a[j]
        if j - i >= k-1:
            ans = max(ans, sum/(j-i+1))
print(ans)