n = int(input())
ans = 0
for i in range(n):
    ans = max(ans, (i + 1) * (n - i))
print(ans)