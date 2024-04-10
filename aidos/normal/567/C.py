n, k = map(int, input().split())
a = map(int, input().split())
b = [dict(), dict()]
ans = 0
for x in a:
    if x % k == 0:
        y = x//k
        ans += b[1].get(y, 0)
        b[1][x] = b[0].get(y, 0) + b[1].get(x, 0)
    b[0][x] = b[0].get(x, 0) + 1
print(ans)