n = int(input())
ans = 0
mi = 10**40
for i in range(n):
    x, y = map(int, input().split())
    mi = min(mi, y)
    ans += x * mi
print(ans)