n = int(input())
ans = 0
for i in range(2, n):
    ans += i * (i+1)
print(ans)