n, y, x = map(int, input().split())
s = input()
s = s[::-1]
ans = 0
for i in range(y):
    if i == x:
        ans += 1-int(s[i])
    else:
        ans += int(s[i])
print(ans)