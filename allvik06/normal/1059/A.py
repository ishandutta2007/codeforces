n, l, a = map(int, input().split())
s = []
for i in range(n):
    s.append([])
    x, y = map(int, input().split())
    s[i].append(x)
    s[i].append(y)
ans = 0
k = 0
for i in range(n):
    if s[i][0] - k >= a:
        ans += (s[i][0] - k) // a
    k = s[i][0] + s[i][1]
if k < l:
    ans += (l - k) // a
print(ans)