n, a = map(int, input().split())
b = list(map(int, input().split()))
a -= 1
ans = b[a]
for d in range(1, n):
    if a - d < 0 and a + d >= n:
        break
    if a-d < 0:
        ans += b[a+d]
    elif a+d >= n:
        ans += b[a-d]
    elif b[a-d] == b[a+d]:
        ans += b[a-d] * 2
print(ans)