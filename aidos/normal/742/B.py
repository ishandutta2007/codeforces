n, x = map(int, input().split())
a = map(int, input().split())
b = dict()
ans = 0
for e in a:
    ans += b.get(e^x, 0)
    b[e] = b.get(e, 0) + 1
print(ans)