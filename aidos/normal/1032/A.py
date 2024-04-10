n, k = map(int, input().split())
a = map(int, input().split())
d = dict()
mx = 0
for i in a:
    d[i] = d.get(i, 0) + 1
    mx = max(mx, d[i])
ans = 0
mx += (k - mx % k) % k
for x, y in d.items():
    ans += mx - y
print(ans)