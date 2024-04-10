n, k = map(int, input().split())
a = list(map(int, input().split()))
b = dict()
ans = 0
for x in a:
    h = b.get((k-x) % k, -1)
    if h > 0:
        b[(k-x) % k] = h - 1
        ans += 2
    else:
        h = b.get(x % k, 0)
        b[x%k] = h + 1
print(ans)