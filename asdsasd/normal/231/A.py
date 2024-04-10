ans = 0
for _ in range(int(input())):
    cnt = sum(map(int, input().split()))
    if cnt >= 2:
        ans += 1
print(ans)