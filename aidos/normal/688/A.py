n, d=map(int, input().split())
ans = 0
cur = 0
for i in range(d):
    x = input()
    if x.count('0') == 0:
        cur = 0
    else:
        cur += 1
    ans = max(ans, cur)
print(ans)