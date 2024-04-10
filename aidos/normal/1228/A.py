l, r = map(int, input().split())
ans = -1
for i in range(l, r + 1):
    s = str(i)
    if len(s) == len(set(s)):
        ans = i
        break
print(ans)