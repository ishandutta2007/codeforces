n = int(input())
ans = 0
for i in range(n):
    a = list(map(int, input().split()))
    for j in range(n):
        if i == n//2 or j == n//2 or (i + j) == n-1 or i == j:
            ans += a[j]
print(ans)