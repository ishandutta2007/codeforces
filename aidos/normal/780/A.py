n = int(input())
a = [False] * n
x = list(map(int, input().split()))
cnt = 0
ans = 0
for y in x:
    y -= 1
    if a[y]:
        cnt -= 1
    else:
        cnt += 1
    a[y] = True
    ans = max(ans, cnt)

print(ans)