n, k = map(int, input().split())

cnt = 240 - k
ans = 0
for i in range(1, n+1):
    if cnt >= i * 5:
        cnt -= i * 5
        ans += 1
print(ans)